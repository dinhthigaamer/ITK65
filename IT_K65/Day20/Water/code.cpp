#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005
#define fi first
#define se second

int n,a[1000005],l[1000005],r[1000005];
int d[MAX],top;
pair<long long ,int> p[MAX],q[MAX];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];

    a[0]=1e9; top=0;
    d[0]=0;
    for(int i=1;i<=n;++i)
    {
        while(a[i]>a[d[top]])
        {
            r[d[top]]=i;
            --top;
        }
        d[++top]=i;
    }

    top=0 ; d[0]=0;

    for(int i=n;i>=1;--i)
    {
        while(a[i]>a[d[top]])
        {
            l[d[top]]=i;
            --top;
        }
        d[++top]=i;
    }

    long long res=0;
    p[1]={a[1],1};
    for(int i=2;i<=n;++i)
    {
        p[i]=p[i-1];
        if(a[i]>=p[i].fi) p[i]={a[i],i};
    }

    q[n]={a[n],n};
    for(int i=n-1;i>=1;--i)
    {
        q[i]=q[i+1];
        if(a[i]>=q[i].fi) q[i]={a[i],i};
    }

    for(int i=1;i<=n;++i)
    {
        long long x=min(p[i].fi,q[i].fi);
        if(x>a[i]) res=(long long ) res+x-a[i];
    }

    long long ans=res;

    for(int i=1;i<=n;++i)
    {
        if(a[i]<p[i].fi&&a[i]<q[i].fi) continue;
        if(a[i]>=p[i].fi&&a[i]>=q[i].fi) continue;
        long long tmp=res;
        long long x=a[i]+1;

        if(x<=p[i].fi) tmp+=i-l[i]-1;
        if(x<=q[i].fi) tmp+=r[i]-i-1;
        ans=max(ans,tmp);
    }
    cout<<ans;
}
