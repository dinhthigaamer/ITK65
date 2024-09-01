#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
#define ll long long
int n,s;
int t[MAX],f[MAX];
ll sum_T[MAX],sum_F[MAX],dp[MAX];
vector<long double> range;
pair<ll,ll> st[MAX];
int p1;

int check(ll a,ll b)
{
    pair<ll,ll> Point1=st[p1];
    if(Point1.first==a) return 0;
    if(p1==1) return 1;

    pair<ll,ll> Point2=st[p1-1];
    double X1=1.00*(Point1.second-b)/(a-Point1.first);
    double X2=1.00*(Point2.second-b)/(a-Point2.first);
    return (X1>X2);
}

void add(ll a,ll b)
{
    while(p1>=1 && !check(a,b))
    {
        --p1 ;
        range.pop_back();
    }
    st[++p1]={a,b};
    if(p1>1)
    {
        range.pop_back();
        long double X= 1.00*(st[p1-1].second-st[p1].second)/(st[p1].first-st[p1-1].first);
        range.push_back(X);
    }
    if(range.back()!=1e18) range.push_back(1e18);
}

int Find(ll x)
{
    int low=1 , high=p1 , ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(range[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;++i) cin>>t[i]>>f[i];
    for(int i=1;i<=n;++i)
    {
        sum_T[i]= sum_T[i-1]+t[i];
        sum_F[i]= sum_F[i-1]+f[i];
    }

    range.push_back(-1e18);
    range.push_back(1e18);
    fill(dp+1,dp+n+1,1e18);
    add(sum_F[n],s*sum_F[n]);

    for(int i=1;i<=n;++i)
    {
        int id=Find(sum_T[i]);
        dp[i]=st[id].first * sum_T[i] + st[id].second;
        /*cout<<id<<endl;
        for(int j=1;j<=p1;++j) cout<<st[j].first<<' '<<st[j].second<<' '<<range[j]<<endl;
        cout<<endl;*/
        add(sum_F[n]-sum_F[i],(s-sum_T[i])*(sum_F[n]-sum_F[i])+dp[i]);

        //cout<<endl;
        /*for(int j=i-1;j>=0;--j)
        {
             dp[i]=min(dp[i],dp[j]+(sum_T[i]-sum_T[j]+s)*(sum_F[n]-sum_F[j]));
        }*/
    }
    //for(int i=1;i<=n;++i) cout<<dp[i]<<' ';
    cout<<dp[n]<<endl;
    return 0;
}