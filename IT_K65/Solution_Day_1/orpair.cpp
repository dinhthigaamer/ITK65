#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define MAX 1000100
#define MASK(x,i) ((x>>i)&1)
#define BIT(i) ((1ll)<<i)

int n;
ll a[MAX];
int cnt[2000010];
int cntbit[25];
vector<int> save[20];

int main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    
    int sumor=0;
    for(int i=1;i<=n;++i) sumor|=a[i];

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<20;++j) if(MASK(a[i],j)) ++cntbit[j];
    }
    for(int i=0;i<20;++i) 
    {   
        if(cntbit[i]==1)
        {
            cout<<0<<endl;
            return 0;
        }
        if(cntbit[i]==2)
        {
            for(int j=1;j<=n;++j) if(MASK(a[j],i)) 
                                   save[i].push_back(j);
        }
    }
  
    for(int i=1;i<=n;++i) ++cnt[a[i]];
    for(int i=0;i<20;++i) for(int mask=0;mask<(1<<20);++mask)
    {
        if(MASK(mask,i))
        {
            cnt[mask^BIT(i)]+=cnt[mask];
        }
    }
 
    long long res=0;

    for(int i=1;i<=n;++i)
    {
        res+=cnt[sumor^a[i]];
        if(a[i]==sumor) --res;
        unordered_map<int,int> s; s.clear();
        
        for(int j=0;j<20;++j) if(MASK(a[i],j) && cntbit[j]==2)
        {
            for(int k:save[j]) if(k!=i && s.count(k)==0)
            {
                if((a[k]|a[i])==sumor) --res;
                s[k]=1;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
