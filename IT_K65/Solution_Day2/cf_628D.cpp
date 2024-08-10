#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int mod = 1e9+7;

string a,b;
int m,d;
int n;
int Pow10[2001]; 
// pow[i]=10^i%m
int f[2001][2][2][2001];

int val(char c)
{
    return c-'0';
}

int add(int A,int B)
{
    A+=B;
    if(A>=mod) A-=mod;
    return A;
}

int dp(int pos,int ok1,int ok2,int remainder)
{
    //cout<<pos<<' '<<ok1<<' '<<ok2<<' '<<remainder<<endl;
    // remainder = (digit[1]*(10^n-1)+digit[2]*(10^(n-2))+...+digit[pos-1]*(n-pos+1)) % m
    if(pos==n+1) return (remainder==0);

    int *tmp = &f[pos][ok1][ok2][remainder];
    if(*tmp!=-1) return *tmp;

    *tmp = 0;

    if(pos%2==0) // digit in pos must be d
    {
        if((ok1==0) && (d < val(a[pos]))) return 0;
        if((ok2==0) && (d > val(b[pos]))) return 0;

        int newRemainder = (remainder + 1ll*d*Pow10[n-pos]%m)%m;
        *tmp = add(*tmp, dp(pos+1, ok1|(d>val(a[pos])), ok2|(d<val(b[pos])), newRemainder)); 
    }
    else 
    {
        for(int i=0;i<=9;++i) if(i!=d)
        {
            if((ok1==0) && (i < val(a[pos]))) continue;
            if((ok2==0) && (i > val(b[pos]))) continue;

            int newRemainder = (remainder + 1ll*i*Pow10[n-pos]%m)%m;
            *tmp = add(*tmp, dp(pos+1, ok1|(i>val(a[pos])), ok2|(i<val(b[pos])), newRemainder)); 
        }
    }
    return *tmp;
}

int main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);

    cin>>m>>d;
    cin>>a>>b;

    while(a.size() < b.size()) a="0"+a;
    n=b.size();
    a=' '+a ; b=' '+b;

    Pow10[0]=1;
    for(int i=1;i<=n;++i) Pow10[i]=1ll*Pow10[i-1]*10%m;

    memset(f,-1,sizeof(f));
    int res = dp(1,0,0,0);

    cout<<res<<endl;

    return 0;
}