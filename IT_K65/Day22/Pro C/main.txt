#include<bits/stdc++.h>
using namespace std;

#define MAX 500005
vector<int> ans;
int q,t[MAX],x[MAX],y[MAX],p[MAX];
int n;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>t[i];
        if(t[i]==1) cin>>x[i] ,++n;
        else cin>>x[i]>>y[i];
    }

    vector<int> p(MAX);
    iota(p.begin(),p.end(),0);
    int j=n;
    for(int i=q;i>=1;--i)
    {
        if(t[i]==1) ans.push_back(p[x[i]]);
        else
            p[x[i]]=p[y[i]];
    }
    reverse(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<' ';
    return 0;
}