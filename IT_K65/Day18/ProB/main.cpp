#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
int n,m;
double x[MAX];

struct Line
{
    long long a,b;
};
int p1;
Line line[MAX],st[MAX];

int check(int p1,Line C)
{
    Line B=st[p1];
    if(C.a==B.a) return 0;
    if(p1==1) return 1;
    double M=1.0*(C.b-B.b)/(B.a-C.a);
    Line A=st[p1-1];
    double N=1.0*(C.b-A.b)/(A.a-C.a);//cout<<M<<' '<<N<<endl;
    return (M>N);
}

int cmp(Line A,Line B)
{
    if(A.a==B.a) return A.b<B.b;
    return A.a<B.a;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>line[i].a>>line[i].b;

    sort(line+1,line+n+1,cmp);

    p1=0;
    for(int i=1;i<=n;++i)
    {
        while(p1>0 && !check(p1,line[i])) --p1;
        st[++p1]=line[i];
    }

    //for(int i=1;i<=p1;++i) cout<<st[i].a<<' '<<st[i].b<<endl;
    x[0]=-2e9 ;
    for(int i=1;i<p1;++i)
    {
        x[i]=1.0*(st[i+1].b-st[i].b)/(st[i].a-st[i+1].a);
    }
    x[p1]=2e9;

    cin>>m;
    for(int i=1;i<=m;++i)
    {
        long long xi; cin>>xi;
        int pos=lower_bound(x,x+p1+1,xi)-x;
        cout<<(long long)st[pos].a*xi+st[pos].b<<'\n';
    }
    return 0;
}