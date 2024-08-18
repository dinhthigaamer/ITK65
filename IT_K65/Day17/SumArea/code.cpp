#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

int n;
struct point
{
    int x,y;

    point operator-(point other)
    {
        return {x-other.x , y-other.y};
    }
    long long cross(point other)
    {
        return 1ll*x*other.y - 1ll*y*other.x;
    }
    long long area(point other)
    {
        point A=(*this);
        return abs(A.cross(other));
    }
};

point p[3005]; //p is point , v is vector
vector<point> v1,v2;
int sumx,sumy;
long double res=0;

void solve()
{
    long double delta=0;
    sort(all(v1),[](point A,point B){return A.cross(B)>0;});
    sort(all(v2),[](point A,point B){return A.cross(B)>0;});
    // dien tich phan phia tren
    sumx=0 ; sumy=0;
    for(int i=0;i<v1.size();++i)
    {
        delta+=v1[i].area({sumx,sumy});
        sumx+=v1[i].x , sumy+=v1[i].y;
    }
    sumx=0 ; sumy=0;
    for(int i=0;i<v2.size();++i)
    {
        delta+=v2[i].area({sumx,sumy});
        sumx+=v2[i].x , sumy+=v2[i].y;
    }
    // tinh tong giao 2 phan
    sumx=0 ; sumy=0;
    for(int i=0;i<v2.size();++i) sumx+=v2[i].x , sumy+=v2[i].y;
    int p=0;
    for(int i=0;i<v1.size();++i)
    {
        while(p<v2.size() && v1[i].cross(v2[p])>0) sumx-=2*v2[p].x , sumy-=2*v2[p].y , ++p;
        delta+=v1[i].area({sumx,sumy});
    }
    res+=delta;
}

int main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>p[i].x>>p[i].y;
    for(int i=1;i<=n;++i)
    {
        v1.clear() ; v2.clear();
        for(int j=1;j<=n;++j)
        {
            point sub=p[j]-p[i];
            if(sub.x==0 && sub.y==0) continue;
            if(sub.y>0 || (sub.y==0 && sub.x>0)) v1.push_back(sub);
            else
            v2.push_back(sub);
        }
        solve();
    }
    res/=6;
    cout<<setprecision(1)<<fixed<<res<<endl;
    return 0;
}