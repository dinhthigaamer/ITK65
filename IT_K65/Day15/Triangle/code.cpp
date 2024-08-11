#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second

struct Point{
     ll x,y;

     Point operator-(Point A){
           return {x-A.x , y-A.y};
     }
     ll dot(Point A){
           return x*A.x + y*A.y;
     }
     ll cross(Point A){
           return x*A.y - y*A.x;
     }
};
int n;
Point P[1505];
map<pll,int> mp;
ll res;

void add(ll x,ll y){
     if(x==0 && y==0) return ;
     if(x==0){
        ++mp[{0,1}];
        return ;
     }
     if(y==0){
        ++mp[{1,0}];
        return ;
     }
     ll d=__gcd(x,y);
     x/=d ; y/=d;

     if(x>0 && y<0){
        x=-x ; y=-y;
     }
     ++mp[{x,y}];
}

void cal(int id){
     mp.clear();
     for(int i=1;i<=n;++i){
         Point vec=P[i]-P[id];
         add(vec.x,vec.y);
     }

     for(auto it:mp){
         int x=it.fi.fi , y=it.fi.se;

         if(x==1 && y==0){
            if(mp.count({0,1})) res+=1ll* it.se * mp[{0,1}];
         }
         else
         if(x==0 && y==1){
             if(mp.count({1,0})) res+=1ll* it.se * mp[{1,0}];
         }
         else{
             if(x<0){
                 if(mp.count({y,-x})) res+=1ll* it.se * mp[{y,-x}];
             }
             else
             {
                 if(mp.count({-y,x})) res+=1ll* it.se * mp[{-y,x}];
             }
         }
     }
     //cout<<res<<endl;
}

int main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>P[i].x>>P[i].y;
    }

    for(int i=1;i<=n;++i){
        cal(i);
    }
    res/=2;
    cout<<res<<endl;
    return 0;
}
