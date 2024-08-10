#include<bits/stdc++.h>
using namespace std;

#define MASK(i) (1<<i)
#define BIT(x,i) ((x>>i)&1)
#define int long long

int n;
int Z[105];
int f[105][10][10],cnt[105][10][10];
vector<int> g[105];

int check(int mask1,int mask2,int mask3)
{
    if(BIT(mask2,0) && BIT(mask1,2)) return 0;
    if(BIT(mask2,2) && BIT(mask1,0)) return 0;
    if(BIT(mask3,0) && BIT(mask2,2)) return 0;
    if(BIT(mask3,2) && BIT(mask2,0)) return 0;
    if(BIT(mask3,0) && BIT(mask1,1)) return 0;
    if(BIT(mask3,1) && (BIT(mask1,0)||BIT(mask1,2))) return 0;
    if(BIT(mask3,2) && BIT(mask1,1)) return 0;
    //cout<<mask1<<' '<<mask2<<' '<<mask3<<endl;
    return 1;
}

int Count(int mask)
{
    return __builtin_popcount(mask);
}

int32_t main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>Z[i] , Z[i]--;

    for(int i=1;i<=n;++i)
    {
        for(int mask=0;mask<8;++mask) if(Z[i]<0 || !BIT(mask,Z[i]))
            g[i].push_back(mask);
    }
    g[0].push_back(0);

    for(int mask:g[1]) f[1][0][mask]=Count(mask) , cnt[1][0][mask]=1;

    for(int i=2;i<=n;++i)
        for(int mask3:g[i])
           for(int mask2:g[i-1])
             for(int mask1:g[i-2]) if(check(mask1,mask2,mask3))
    {
         int &X=f[i][mask2][mask3];
         int &Y=cnt[i][mask2][mask3];

         if(X<f[i-1][mask1][mask2]+Count(mask3))
         {
             X=f[i-1][mask1][mask2]+Count(mask3);
             Y=cnt[i-1][mask1][mask2];
         }
         else
         if(X==f[i-1][mask1][mask2]+Count(mask3))
            Y+=cnt[i-1][mask1][mask2];
    }

    int res=0 , dem=0;
    for(int mask2:g[n])
        for(int mask1:g[n-1])
    {
        if(f[n][mask1][mask2]>res)
        {
            res=f[n][mask1][mask2];
            dem=cnt[n][mask1][mask2];
        }
        else
        if(f[n][mask1][mask2]==res)
             dem+=cnt[n][mask1][mask2];
    }
    cout<<res<<' '<<dem<<endl;
    return 0;
}
