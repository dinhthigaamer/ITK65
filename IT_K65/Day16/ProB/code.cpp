#include<bits/stdc++.h>
using namespace std;

int n;
int a[505];
int f[505][505];
int dp[505];

int main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];

    for(int i=1;i<=n;++i) f[i][i]=a[i];
    for(int l=2;l<=n;++l)
        for(int i=1;i+l-1<=n;++i)
        {
            int j=i+l-1;
            for(int k=i+1;k<=j;++k) if(f[i][k-1] && f[i][k-1]==f[k][j])
            {
                f[i][j]=f[i][k-1]+1;
                break;
            }
        }
    /*for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j) cout<<f[i][j]<<' ';
        cout<<endl;
    }*/
    for(int i=1;i<=n;++i)
    {
        dp[i]=1e9;
        for(int j=0;j<i;++j) if(f[j+1][i])
            dp[i]=min(dp[i],dp[j]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}