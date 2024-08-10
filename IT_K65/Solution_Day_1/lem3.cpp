#include<bits/stdc++.h>
using namespace std;

int n,a[20][20],f[1<<20][20];

int get(int x,int i)
{
    return (x>>(i-1))&1;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) cin>>a[i][j];

    int xx=(1<<n)-1;
    for(int x=0;x<=xx;++x)
    {
        int t[20] ,cnt=0;

        for(int i=1;i<=n;++i) t[i]=0;
        for(int i=1;i<=n;++i) if(get(x,i)) t[++cnt]=i;
        if(cnt<2) continue;
        for(int i=1;i<=cnt;++i)
        {
            f[x][t[i]]=1e9;
            int x1=x-(1<<(t[i]-1));
            for(int j=1;j<=cnt;++j) if(i!=j)
            {
                f[x][t[i]]=min(f[x][t[i]],f[x1][t[j]]+a[t[j]][t[i]]);
            }
        }
    }
    cout<<*min_element(f[xx]+1,f[xx]+n+1);
}
