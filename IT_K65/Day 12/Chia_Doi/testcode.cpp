#include<bits/stdc++.h>
using namespace std;
int n,m;
int u[100001],v[100001];
vector<int>g[100001];
int in[1000001];
bitset<50001>dp;
int l1,l2;
bool dfs(int u){
    for(int v:g[u]){
        if(!in[v]){
            if(in[u]==1){
                in[v]=2;
                l2++;
            }
            else{
                in[v]=1;
                l1++;
            }
            dfs(v);
        }
        else if(in[v]==in[u])return false;
    }
    return true;
}
bool check(int x){
    fill_n(in,n+1,0);
    for(int i=1;i<=n;i++)g[i].clear();
    dp=0;
    dp[0]=1;
    for(int i=1;i<=x;i++){
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    for(int i=1;i<=n;i++){
        if(!in[i]){
            l1=1;
            l2=0;
            in[i]=1;
            if(!dfs(i))return false;
            else dp=dp|(dp<<l1)|(dp<<l2);
        }
    }
    return dp[n/2];
}
void process(){
    cout<<check(4);
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>u[i]>>v[i];
}

void File()
{
    freopen("file.inp", "r", stdin);
    freopen("file.out", "w", stdout);
}

int main(){
    File();
    ios_base::sync_with_stdio(0);cin.tie(0);
    init();
    process();
}