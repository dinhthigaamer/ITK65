#include<bits/stdc++.h>
using namespace std;

#define int long long

int m,n;
int a[405][405],b[405][405];
int dp[405][405],h[405];
int cnt[35];
int st[405]; // stack

void dynamic_programming(int MASK)
{
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j)
        b[i][j]=(MASK>>a[i][j])&1;

    memset(dp,0,sizeof(dp));
    memset(h,0,sizeof(h));
    for(int i=1;i<=m;++i)
    {
        int p1=0;
        for(int j=1;j<=n;++j) if(b[i][j])
        {
            if(b[i-1][j]) ++h[j] ; else h[j]=1;
            while(p1 && h[st[p1]]>=h[j]) --p1;
            int k=st[p1];

            dp[i][j]=(long long) dp[i][k]+dp[i-h[j]][j]+(j-k)*h[j];
            st[++p1]=j;
        }
        else
        {
            h[j]=0;
            st[++p1]=j;
        }
    }
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) cnt[MASK]+=dp[i][j];
    /*if(MASK==7)
    {
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j) cout<<dp[i][j]<<' ';
            cout<<endl;
        }
    }*/
}

int32_t main()
{
    cin>>m>>n;
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j)
    {
        char x;
        cin>>x;
        a[i][j]=x-'A';
    }

    memset(cnt,0,sizeof(cnt));
    for(int mask=0;mask<(1<<5);++mask)
    {
        dynamic_programming(mask);
    }

    long long res=0;
    for(int mask=0;mask<32;++mask)
    {
        //for(int i=4;i>=0;--i) cout<<((mask>>i)&1); cout<<' '<<cnt[mask]<<' ';
        for(int submask=(mask-1)&mask;submask;submask=(submask-1)&mask)
        {
            int x=__builtin_popcount(submask);
            if(x%2) cnt[mask]-=cnt[submask];
            else cnt[mask]-=cnt[submask];
        }

        //cout<<cnt[mask]<<endl;
        if(__builtin_popcount(mask)==3) res+=cnt[mask];
    }
    cout<<res<<endl;
    return 0;
}
