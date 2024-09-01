#include<bits/stdc++.h>
using namespace std;

int s[4005][4005],a[4005][4005];
vector<int> dp_cur,dp_before;
int n,m;

int readint()
{
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    int x=ch-'0';
    ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

int get(int i,int j)
{
    return (s[j][j]-s[i-1][j]-s[j][i-1]+s[i-1][i-1]);
}

void dynamic(int l,int r,int optl,int optr)
{
    if(l>r) return ;
    int mid=(l+r)/2;
    pair<int ,int> best={1e9,n};
    for(int i=optl;i<=min(mid,optr);++i) if(i>1) best=min(best,{ dp_before[i-1]+get(i,mid),i});
                                        else best=min(best,{get(i,mid),i});
    dp_cur[mid]=best.first;
    int opt=best.second;

    dynamic(l,mid-1,optl,opt);
    dynamic(mid+1,r,opt,optr);
}

int main()
{
    n=readint();
    m=readint();
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
    {
        a[i][j]=readint();
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }
    dp_cur.resize(n+1);
    dp_before.resize(n+1);
    for(int i=1;i<=n;++i) dp_before[i]=get(1,i);

    for(int i=2;i<=m;++i)
    {
        dynamic(1,n,1,n);
        dp_before.swap(dp_cur);
    }
    cout<<dp_before[n]/2;
     return 0;
}