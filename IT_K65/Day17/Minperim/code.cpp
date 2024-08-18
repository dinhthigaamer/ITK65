#include<bits/stdc++.h>
using namespace std;

#define double long double
int n,m;
double d[102][102];

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
    int operator<(const point other)const
    {
        return (x<other.x || (x==other.x && y<other.y));
    }
};
point p1[102],p2[102];

int ccw(point A,point B,point C)
{
    int x=(B-A).cross(C-A);
    if(x==0) return 0;
    if(x>0) return 1;
    return -1;
}

int check(point A,point B)
{
    for(int i=1;i<=n;++i) if(ccw(A,B,p1[i])<=0) return 0;
    return 1;
}

double dis(point A,point B)
{
    double x=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    x=sqrt(x);
    return x;
}

void build_graph()
{
    for(int u=1;u<=m;++u) for(int v=1;v<=m;++v) d[u][v]=1e15;
    for(int u=1;u<=m;++u)
        for(int v=1;v<=m;++v)
        {
            if(u==v) d[u][u]=0;
            else
            if(check(p2[u],p2[v])) d[u][v]=dis(p2[u],p2[v]);
        }
}

void floyd()
{
    for(int i=1;i<=m;++i)
        for(int u=1;u<=m;++u)
          for(int v=1;v<=m;++v) d[u][v]=min(d[u][v],d[u][i]+d[i][v]);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>p1[i].x>>p1[i].y;
    sort(p1+1,p1+n+1);

    cin>>m;
    for(int i=1;i<=m;++i) cin>>p2[i].x>>p2[i].y;
    sort(p2+1,p2+m+1);

    build_graph();
    floyd();
    /*for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j) cout<<d[i][j]<<' ';
        cout<<endl;
    }*/
    double res=1e18;
    for(int u=1;u<=m;++u) if(p2[u].x<p1[1].x)
        for(int v=1;v<=m;++v) if(p2[v].x>p1[n].x) res=min(res,d[u][v]+d[v][u]);
    cout<<setprecision(2)<<fixed<<res<<endl;
    return 0;
}