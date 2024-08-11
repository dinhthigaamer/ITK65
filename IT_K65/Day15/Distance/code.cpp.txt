#include<bits/stdc++.h>
using namespace std;

#define ld long double

struct Point{
    ld x,y;

    Point operator-(Point A){
        return {x-A.x , y-A.y};
    }
    ld cross(Point A){
        return x*A.y - y*A.x;
    }
    ld dot(Point A){
        return x*A.x + y*A.y;
    }
};

int n;
Point Bill,P[1005];

ld dis(Point A,Point B){
   return (B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y);
}

ld cal(Point C,Point D){
   if((C-Bill).cross(D-Bill)==0) return sqrt(min(dis(Bill,C),dis(Bill,D)));
   if((Bill-C).dot(D-C)<=0){
       return sqrt(dis(Bill,C));
   }
   if((Bill-D).dot(C-D)<=0){
       return sqrt(dis(Bill,D));
   }
   ld S=(C-Bill).cross(D-Bill); S=S*S;
   S/=dis(C,D);
   S=sqrt(S);
   return S;
}

int main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    cin>>n;
    cin>>Bill.x>>Bill.y;
    for(int i=1;i<=n;++i) cin>>P[i].x>>P[i].y;
    P[n+1]=P[1];

    ld res=1e18;
    for(int i=1;i<=n;++i){
        ld distance=cal(P[i],P[i+1]);
        res=min(res,distance);
    }
    cout<<setprecision(4)<<fixed<<res<<endl;
    return 0;
}
