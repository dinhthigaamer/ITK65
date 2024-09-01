#include<bits/stdc++.h>
using namespace std;

#define MAX 50050
#define pii pair<long long,long long>
#define ll long long
#define fi first
#define se second

int n;
pii b[MAX],a[MAX];
int p1,p2,st[MAX];
ll f[MAX];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>b[i].fi>>b[i].se;
    sort(b+1,b+n+1);

    int bmax=b[n].se;
    p1=0;
    st[++p1]=n;
    for(int i=n-1;i>=1;--i)
    {
        if(bmax>=b[i].se) continue;
        else
        {
            st[++p1]=i;
            bmax=b[i].se;
        }
    }

    for(int i=1;i<=p1;++i) a[i]=b[st[i]];
    n=p1;

    memset(f,0x3f3f3f,sizeof(f));

    p1=1;
    p2=1;
    vector<pair<ll,ll>> v;
    //q*x+p
    f[1]=a[1].fi*a[1].se;
    v.push_back({a[1].fi,0});
    for(int i=2;i<=n;++i)
    {
        //insert new line a[i]*x+f[i-1]
        while(p1>0)
        {
            if(v[p1-1].fi==a[i].fi) {--p1 ; v.pop_back() ; continue;}
            if(p1==1) break;
            double M=1.0*(f[i-1]-v[p1-1].se)/(v[p1-1].fi-a[i].fi);
            double N=1.0*(f[i-1]-v[p1-2].se)/(v[p1-2].fi-a[i].fi);
            if(M<=N)
            {
                v.pop_back();
                --p1;
                continue;
            }
            else break;
        }
        v.push_back({a[i].fi,f[i-1]}); ++p1;
        if(p2>=p1) p2=p1-1;

        if(p2==0) ++p2;
        while(p2<p1 && (v[p2].fi*a[i].se+v[p2].se)<=(v[p2-1].fi*a[i].se+v[p2-1].se)) ++p2;
        --p2;
        f[i]=v[p2].fi*a[i].se+v[p2].se;
    }
    //for(int i=1;i<=n;++i) cout<<f[i]<<' ';cout<<endl;
    cout<<f[n]<<endl;
    return 0;
}