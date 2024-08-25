#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;

struct point
{
    int x,y;
    point operator-(point other)
    {
        return {x-other.x , y-other.y};
    }
    int dot(point other)
    {
        return x*other.x + y*other.y;
    }
    int cross(point other)
    {
        return x*other.y - y*other.x;
    }
    bool operator<(const point& other)const
    {
        if(x==other.x) return y<other.y;
        return x<other.x;
    }
};

vector<point> P1,P2;
vector<point> poly1,poly2;
point F;

int ccw(point A,point B,point C)
{
    int x=(B-A).cross(C-A);
    if(x==0) return 0;
    if(x>0) return 1;
    return -1;
}

vector<point> convex_hull(vector<point> P)
{
   sort(P.begin(),P.end());
   vector<point> res;

   int m=-1;
   for(int i=0;i<n;++i)
   {
       while(m>=1 && ccw(res[m-1],res[m],P[i])<=0) --m , res.pop_back();
       ++m;
       res.push_back(P[i]);
   }
   int m1=m;
   for(int i=n-2;i>=0;--i)
   {
       while(m>m1 && ccw(res[m-1],res[m],P[i])<=0) --m , res.pop_back();
       ++m;
       res.push_back(P[i]);
   }
   res.pop_back() ; --m;
   return res;
}

int inside(point A,point B,point C)
{
    return (A-B).dot(A-C)<=0;
}

int area(vector<point> Tri)
{
    return abs((Tri[2]-Tri[0]).cross(Tri[1]-Tri[0]));
}

int inside(point A,vector<point> P)
{
    int m=P.size();
    if(m==1) return (A.x==P[0].x && A.y==P[0].y);
    if(m==2) return inside(A,P[0],P[1]);

    int x=ccw(P[0],P[1],A) , y=ccw(P[0],P[m-1],A);
    if(x*y>0) return 0; // nam cung phia o ngoai
    if(x==0)  return inside(A,P[0],P[1]);
    if(y==0)  return inside(A,P[0],P[m-1]);

    int low=1 , high=m-1;
    while(high-low>1)
    {
        int mid=(low+high)/2;
        int x=ccw(P[0],P[mid],A);
        if(x==0) return inside(A,P[0],P[mid]);
        if(x>0) low=mid ;
        else high=mid;
    }
    return (area({P[0],P[low],A})+area({P[0],P[high],A})+area({P[low],P[high],A})==area({P[0],P[low],P[high]}));
}

int32_t main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n;
    for(int x,y,i=1;i<=n;++i)
    {
        cin>>x>>y;
        P1.push_back({x,y});
    }
    for(int x,y,i=1;i<=n;++i)
    {
        cin>>x>>y;
        P2.push_back({x,y});
    }
    poly1 = convex_hull(P1);
    poly2 = convex_hull(P2);
    int res1=0 , res2=0;
    for(auto it:P1) if(inside(it,poly2)) ++res2;
    for(auto it:P2) if(inside(it,poly1)) ++res1;
    cout<<res1<<' '<<res2<<endl;
    return 0;
}