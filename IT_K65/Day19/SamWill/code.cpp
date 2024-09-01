#include<bits/stdc++.h>
using namespace std;

#define MAX 200005
typedef long long ll;
int n;
ll d[MAX],w[MAX],sumd[MAX],sumw[MAX],sumwd[MAX],best[MAX];

ll read()
{
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    ll x=ch-'0';
    ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-48;
        ch=getchar();
    }
    return x;
}

ll cal(int i,int j)
{
   return sumd[j-1]*(sumw[j-1]-sumw[i-1])-(sumwd[j-1]-sumwd[i-1]);
}

ll eval(int i,int j)
{
    return cal(1,i)+cal(i+1,j)+cal(j+1,n+1);
}

void solve(int l,int r,int optl,int optr)
{
   if(l>r) return ;
   int mid=(l+r)/2;
   best[mid]=optl;
   for(int i=optl+1;i<=optr;++i)
        if(eval(mid,best[mid])>eval(mid,i)) best[mid]=i;
   solve(l,mid-1,optl,best[mid]);
   solve(mid+1,r,best[mid],optr);
}

int main()
{
   n=read();
   for(int i=1;i<=n;++i)
   {
       w[i]=read();
       d[i]=read();
       sumd[i]=sumd[i-1]+d[i];
       sumw[i]=sumw[i-1]+w[i];
       sumwd[i]=sumwd[i-1]+w[i]*sumd[i-1];
   }
   ll ans=1e18;
   solve(1,n,1,n);
   for(int i=1;i<=n;++i) ans=min(ans,eval(i,best[i]));
   cout<<ans;
   return 0;
}