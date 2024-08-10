#include<bits/stdc++.h>
using namespace std;

#define MASK(i) (1<<i)
#define BIT(x,i) ((x>>i)&1)

int n;
int a[105];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59}; // 17 so
int dp[105][(1<<17)],trace[105][(1<<17)];
int factor[66];

int main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];

    for(int i=2;i<=60;++i){
        int x=i;
        for(int j=0;j<17 && x>1;++j) if(x%prime[j]==0){
            factor[i]^=MASK(j);
            while(x%prime[j]==0){
                x/=prime[j];
            }
        }
    }

    int xxx=MASK(17)-1;

    memset(dp,0x3f3f3f,sizeof(dp));
    dp[0][0]=0;

    for(int i=1;i<=n;++i){
        for(int mask=0;mask<=xxx;++mask){
            for(int j=1;j<=60;++j) if((factor[j]&mask)==factor[j]){
                if(dp[i][mask]>dp[i-1][mask^factor[j]]+abs(a[i]-j)){
                    trace[i][mask]=j;
                    dp[i][mask]=dp[i-1][mask^factor[j]]+abs(a[i]-j);
                }
            }
        }
    }
    int best=0,ans=1e9;
    for(int mask=0;mask<=xxx;++mask){
        if(dp[n][mask]<ans){
            ans=dp[n][mask];
            best=mask;
        }
    }

    vector<int> vec;
    int id=n;
    while(id>0){
        vec.push_back(trace[id][best]);
        best^=factor[trace[id][best]];
        --id;
    }
    reverse(vec.begin(),vec.end());
    for(int it:vec) cout<<it<<' ';
    return 0;
}