#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100010
long long level[MAX];
int cnt;

void init()
{
    level[0]=1;
    level[1]=2;
    cnt=1;

    for(;;)
    {
        ++cnt;
        level[cnt]=level[cnt-1]+level[cnt-2];
        if(level[cnt]>=1e18) break;
    }
}

void solve()
{
     ll x;
     cin>>x;

     int res=upper_bound(level,level+cnt+1,x)-level-1;
     cout<<res<<'\n';
}

int main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);

    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int test;
    init();
//cout<<level[cnt]<<endl;
    cin>>test;

    while(test--)
    {
        solve();
    }

    return 0;
}
