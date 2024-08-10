#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

int n,m;
ll l[MAX],r[MAX],a[MAX];

struct brute_force{
     ll dp[MAX][2];

     void solve(){
          memset(dp,0,sizeof(dp));

          for(int i=1;i<=n;++i){
              dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
              dp[i][1]=-1e15;

              for(int j=0;j<i;++j){
                  ll sum=0;
                  for(int k=1;k<=m;++k){
                      if(j<l[k] && l[k]<=i && i<=r[k]) sum+=a[k];
                  }
                  //cerr<<j<<' '<<i<<endl;
                  dp[i][1]=max(dp[i][1],dp[j][1]+sum);
              }
          }
          cout<<max(dp[n][0],dp[n][1])<<endl;
     }
}trau;

struct Full{
    vector<pii> vec[MAX];
    ll val[MAX],dp[MAX][2];

    class segment_tree{
    public:
          int L,R,mid;
          ll value,lazy;
          segment_tree *left,*right;

          segment_tree(int u,int v):L(u),R(v),mid((u+v)/2){
              value=lazy=0;
              if(L==R) return ;

              left=new segment_tree(L,mid);
              right=new segment_tree(mid+1,R);
          }

          void down(){
               if(lazy!=0){
                  left->value += lazy;
                  right->value += lazy;
                  left->lazy += lazy;
                  right->lazy +=lazy;
                  lazy=0;
               }
          }

          void up(int u,int v,ll val){
               if(L>v || u>R) return ;
               if(u<=L && R<=v){
                  value+=val;
                  lazy+=val;
                  return ;
               }
               down();

               left->up(u,v,val);
               right->up(u,v,val);
               value=max(left->value,right->value);
          }

          ll getmax(int u,int v){
             if(L>v || u>R) return 0;
             if(u<=L && R<=v) return value;
             down();
             return max(left->getmax(u,v) , right->getmax(u,v));
          }
    };

    segment_tree *tree;

    struct que{
        int L,R,V;
        bool operator <(const que& other)const{
             if(L!=other.L) return L<other.L;
             return R<other.R;
        }
    };

    void solve(){
         for(int i=1;i<=m;++i){
             vec[l[i]].push_back({1,i});
             if(r[i]<n) vec[r[i]+1].push_back({-1,i});

             //update for all segment
             val[l[i]]+=a[i];
             if(r[i]<n) val[r[i]+1]-=a[i];
         }
         tree = new segment_tree(1,n);

         for(int i=1;i<=n;++i) val[i]+=val[i-1];

         for(int i=1;i<=n;++i){
             for(pii it:vec[i]){
                int id=it.se;

                if(it.fi == 1){
                    tree->up(l[id],r[id],-a[id]);
                }
                else{
                    tree->up(l[id],r[id],a[id]);
                }
             }

             dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
             dp[i][1]=tree->getmax(1,i-1) + val[i];
             tree->up(i,i,dp[i][1]);
         }

         cout<<max(dp[n][0],dp[n][1])<<endl;
    }
}opt;

int main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>l[i]>>r[i]>>a[i];
    }

    //trau.solve();
    opt.solve();
    return 0;
}
