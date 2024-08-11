#include<bits/stdc++.h>
using namespace std;

#define MAX 500010
#define ll long long 

int n,q;
ll cnt[MAX], a[MAX];

void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(i>1 && a[i]<=a[i-1]) cnt[i]=a[i-1]-a[i]+1; 
        cnt[i]+=cnt[i-1];
    }

    for(int i=1;i<=q;++i)
    {
        int l,r;
        cin>>l>>r;
        cout<<cnt[r]-cnt[l]<<'\n';
    }

    for(int i=1;i<=n;++i) cnt[i]=0;
}

void File()
{
    freopen("file.inp","r",stdin);
    freopen("file.out","w",stdout);
}

int main()
{
    //File();

    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int test=1;

    while(test--)
    {
        solve();
    }

    return 0;
}