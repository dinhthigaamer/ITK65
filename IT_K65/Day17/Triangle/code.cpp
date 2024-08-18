#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
#define ll long long

int n;

struct point
{
    int x,y;
    point operator-(point other)
    {
        return {x-other.x , y-other.y};
    }
    ll dot(point other)
    {
        return 1ll*x*other.x + 1ll*y*other.y;
    }
    ll cross(point other)
    {
        return 1ll*x*other.y - 1ll*y*other.x;
    }
};
point P,p[MAX];
vector<point> p1,p2;

int main()
{
    cin>>n;
    cin>>P.x>>P.y;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i].x>>p[i].y;
        p[i]=p[i]-P;
        if(p[i].y>0 || (p[i].y==0 && p[i].x>0)) p1.push_back(p[i]);
        else p2.push_back(p[i]);
    }
    sort(p1.begin(),p1.end(),[&](point A,point B){return A.cross(B)>0;});
    sort(p2.begin(),p2.end(),[&](point A,point B){return A.cross(B)>0;});
    long long res=0;
    // 1 tren 2 duoi
    int l1=0 , l2=0;
    for(int i=0;i<p1.size();++i) if(p1[i].y>0)
    {
        while(l1<p2.size() && p1[i].cross(p2[l1])>0) ++l1;
        while(l2<p2.size() && p1[i].cross(p2[l2])>=0) ++l2;
        res+=1ll*l1*(p2.size()-l2);
    }
    // 1 duoi 2 tren
    l1=0 , l2=0;
    for(int i=0;i<p2.size();++i) if(p2[i].y<0)
    {
        while(l1<p1.size() && p2[i].cross(p1[l1])>0) ++l1;
        while(l2<p1.size() && p2[i].cross(p1[l2])>=0) ++l2;
        res+=1ll*l1*(p1.size()-l2);
    }
    cout<<res<<endl;
    return 0;
}