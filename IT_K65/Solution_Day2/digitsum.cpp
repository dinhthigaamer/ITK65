#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int modul=1e9+7;

string s;
int d,n;
int k[10005],dp[10005][101][2];

int add(int a,int b)
{
    int c=a+b;
    if(c>=modul) c-=modul;
    return c;
}

int sub(int a,int b)
{
    int c=a-b;
    if(c<0) c+=modul;
    return c;
}

int cal(int pos,int mod,int ok)
{
    int x=dp[pos][mod][ok];
    if(x!=-1) return x;
    if(pos==n)
    {
        if(mod==0) return 1;
        else return 0;
    }
    x=0;
    for(int i=0;i<=max(ok*9,k[pos+1]);++i) x=add(x,cal(pos+1,(mod+i)%d,(ok|(i<k[pos+1]))));
    return dp[pos][mod][ok]=x;
}

int main()
{
    cin>>s;
    cin>>d;
    n=s.size();
    for(int i=1;i<=s.size();++i) k[i]=s[i-1]-'0';
    memset(dp,-1,sizeof(dp));

    cout<<sub(cal(0,0,0),1);

    return 0;
}
