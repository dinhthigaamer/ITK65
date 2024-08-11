#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

struct Point{
     int x,y;

     Point operator-(Point A){
           return {x-A.x , y-A.y};
     }
     int dot(Point A){
           return x*A.x + y*A.y;
     }
     int cross(Point A){
           return x*A.y - y*A.x;
     }
};

bool operator==(Point A,Point B){
     return (A.x==B.x && A.y==B.y);
}

int n;
Point P[2005];
map<pii,int> mp;
ll sum;

void add(int x,int y){
     int d=__gcd(x,y);
     x/=d;y/=d;
     ++mp[{x,y}];
}

ll cal(int id){
     mp.clear();
     ll res=0;

     for(int i=1;i<=n;++i) if(i!=id){
          Point vec=P[i]-P[id];
          if(vec.x==0 && vec.y==0) ++mp[{0,0}];
          else
          if(vec.x==0) ++mp[{0,1}];
          else
          if(vec.y==0) ++mp[{1,0}];
          else
          add(vec.x,vec.y);
     }

     for(auto it:mp){
         if(it.fi.fi==0 && it.fi.se==0){
             res+=1ll*mp[{0,0}]*(mp[{0,0}]-1)/2;
             res+=1ll*mp[{0,0}]*(n-1-mp[{0,0}]);
         }
         else
         {
             res+=1ll*it.se*(it.se-1)/2;
         }
     }
     return res;
}

int main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
         cin>>P[i].x>>P[i].y;
    }

    for(int i=1;i<=n;++i){
        sum+=cal(i);
    }
    sum/=3;
    cout<<sum<<endl;
    return 0;
}
