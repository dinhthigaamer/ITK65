#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MASK(i) (1ll<<i)
#define BIT(x,i) ((x>>i)&1ll)

ll f[31][31][2][2];
ll n,k;

ll dp(int pos,int cnt,int nonzero,int ok)
{
    if(pos<0)
    {
        if(!nonzero) ++cnt;
        return (cnt==k);
    }
    if(cnt>k) return 0;

    ll &x=f[pos][cnt][nonzero][ok];
    if(x!=-1) return x;
    x=0;

    int bit1=BIT(n,pos);
    if(ok)
    {
        //choose 1
        x+=dp(pos-1,cnt,1,1);
        //choose 0
        x+=dp(pos-1,(cnt+1)*nonzero,nonzero,1);
    }
    else
    {
        if(bit1==0) x+=dp(pos-1,(cnt+1)*nonzero,nonzero,0);
        else
        {
            //choose 1
            x+=dp(pos-1,cnt,1,0);
            //choose 0
            x+=dp(pos-1,(cnt+1)*nonzero,nonzero,1);
        }
    }
    return x;
}

int main()
{
    while(cin>>n>>k)
    {
        memset(f,-1,sizeof(f));
        cout<<dp(30,0,0,0)<<'\n';
    }
    return 0;
}
