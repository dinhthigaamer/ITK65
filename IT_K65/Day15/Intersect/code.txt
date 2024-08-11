#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Point{
     int x,y;

     Point operator+(const Point&other)const{
           return {x+other.x , y+other.y};
     }
     Point operator-(const Point&other)const{
           return {x-other.x , y-other.y};
     }
     int dot(const Point&other)const{
           return x*other.x + y*other.y;
     }
     int cross(const Point&other)const{
           return x*other.y - y*other.x;
     }
};

bool operator==(Point A,Point B){
     return (A.x==B.x && A.y==B.y);
}

Point P[8];

int ccw(Point A,Point B,Point C){
    int x=(B-A).cross(C-A);
    if(x==0) return 0;
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}

int check(){
    if(ccw(P[1],P[2],P[3])*ccw(P[1],P[2],P[4])<0 && ccw(P[3],P[4],P[1])*ccw(P[3],P[4],P[2])<0){
            return 1;
    }
    // 3 diem thang hang
    if(ccw(P[1],P[2],P[3])==0){
        if((P[1]-P[3]).dot(P[2]-P[3])<=0) return 1;
    }
    if(ccw(P[1],P[2],P[4])==0){
        if((P[1]-P[4]).dot(P[2]-P[4])<=0) return 1;
    }
    if(ccw(P[3],P[4],P[1])==0){
        if((P[3]-P[1]).dot(P[4]-P[1])<=0) return 1;
    }
    if(ccw(P[3],P[4],P[2])==0){
        if((P[3]-P[2]).dot(P[4]-P[1])<=0) return 1;
    }
    return 0;
}

int32_t main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    int Test;
    cin>>Test;
    for(int i=1;i<=Test;++i){
         for(int j=1;j<=4;++j){
             cin>>P[j].x>>P[j].y;
         }
         int res=check();
         if(res==0) puts("NO");
         else
         puts("YES");
    }
    return 0;
}
