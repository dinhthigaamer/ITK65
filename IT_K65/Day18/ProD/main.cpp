#include<bits/stdc++.h>
using namespace std;

#define MAX 1000010
#define ll long long
#define fi first
#define se second
#define sqr(x) (x*x)

int n;
ll A,B,C;
ll a[MAX];
ll sum[MAX],f[MAX];

int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n;
    cin>>A>>B>>C;
    for(int i=1;i<=n;++i) cin>>a[i];
    sum[0]=0;
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];

    f[0]=0;
    vector<pair<ll,ll>> v;
    v.push_back({0,0});
    int p1=1;
    int p2=1;

    for(int i=1;i<=n;++i)
    {
        if(p2==0) ++p2;
        f[i]=A*sqr(sum[i])+B*sum[i]+C;
        while(p2<p1 && (v[p2].fi*sum[i]+v[p2].se)>=(v[p2-1].fi*sum[i]+v[p2-1].se)) ++p2;
        --p2;

        f[i]+=v[p2].fi*sum[i]+v[p2].se;
        // insert new line
        ll q=-2*A*sum[i] , p=f[i]+A*sqr(sum[i])-B*sum[i];
        while(p1>0)
        {
            if(v[p1-1].fi==q && v[p1-1].se<=p) {v.pop_back() ; --p1 ; continue;}
            if(p1==1) break;
            double M=1.0*(p-v[p1-1].se)/(v[p1-1].fi-q);
            double N=1.0*(p-v[p1-2].se)/(v[p1-2].fi-q);
            if(M<=N) {v.pop_back() ; --p1 ; continue;}
            else break;
        }
        if(v[p1-1].fi<q || v[p1-1].se<p) v.push_back({q,p}) , ++p1;
        if(p2>=p1) p2=p1-1;
    }
    //for(int i=1;i<=n;++i) cout<<f[i]<<' ';
    cout<<f[n]<<endl;
    return 0;
}