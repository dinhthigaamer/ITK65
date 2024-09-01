#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 300005

vector<int> B,M;
int a[MAX],c,n;
int f[MAX];

int bad(int l1,int l2,int l3)
{
    return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);
}

void ins(int m,int b)
{
    M.push_back(m);
    B.push_back(b);
    while(B.size()>2 && bad(B.size()-3,B.size()-2,B.size()-1))
    {
        B.erase(B.end()-2);
        M.erase(M.end()-2);
    }
}

int pointer;

int get(int x)
{
    if(pointer>=B.size()) pointer=B.size()-1;
    while(pointer<B.size()-1 && M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
    {
        ++pointer;
    }
    return M[pointer]*x+B[pointer];
}

int32_t main()
{
    cin>>n>>c;
    for(int i=1;i<=n;++i) cin>>a[i];

    f[1]=0;
    ins(-2*a[1],a[1]*a[1]);
    for(int i=2;i<=n;++i)
    {
        int x=get(a[i]);
        f[i]=x+c+a[i]*a[i];
        ins(-2*a[i],f[i]+a[i]*a[i]);
    }
    //for(int i=1;i<n;++i) cout<<f[i]<<' ';
    cout<<f[n]<<endl;
    return 0;
}
