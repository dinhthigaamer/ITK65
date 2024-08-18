#include<bits/stdc++.h>
using namespace std;

#define MAX 10010
const double pi=3.14159;

int n,m,r;

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
    bool operator<(point other)const
    {
        return (x<other.x || (x==other.x && y<other.y));
    }
};
point b[MAX],p[MAX];

int ccw(point A,point B,point C)
{
    int x=(B-A).cross(C-A);
    if(x==0) return 0;
    if(x>0) return 1;
    if(x<0) return -1;
}

void convexhull()
{
    sort(p+1,p+n+1);
    m=0;
    for(int i=1;i<=n;++i)
    {
        while(m>1 && ccw(b[m-1],b[m],p[i])<=0) --m;
        b[++m]=p[i];
    }
    int m1=m;
    for(int i=n-1;i>=1;--i)
    {
        while(m>m1 && ccw(b[m-1],b[m],p[i])<=0) --m;
        b[++m]=p[i];
    }
    --m;
}

double dis(point A,point B)
{
    double x=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    x=sqrt(x);
    return x;
}

int main()
{
    cin>>n>>r;
    for(int i=1;i<=n;++i) cin>>p[i].x>>p[i].y;

    convexhull();
    double res=dis(b[1],b[m]);
    for(int i=1;i<m;++i) res+=dis(b[i],b[i+1]);
    res+=2*pi*r;
    cout<<setprecision(3)<<fixed<<res<<endl;
    return 0;
}