#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
struct node
{
   int n00,n01,n11;
   void init(int x)
   {
       n01=-1e9;
       if(x==1) n11=1 , n00=-1e9;
       else
       n00=1 , n11=-1e9;
   }
};

int n,q;
node st[MAX*4];
int a[MAX];

node merge(node a,node b)
{
    node c;
    c.n00=max({a.n00,b.n00,a.n00+b.n00});
    c.n11=max({a.n11,b.n11,a.n11+b.n11});
    c.n01=max({a.n01,b.n01,a.n00+b.n11,a.n00+b.n01,a.n01+b.n11});
    return c;
}

void build(int id,int l,int r)
{
    if(l>r) return;
    if(l==r)
    {
        st[id].init(a[l]);
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid) ; build(id*2+1,mid+1,r);
    st[id]=merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int u)
{
    if(u>r || u<l) return ;
    if(u==l && u==r)
    {
        a[u]^=1;
        st[id].init(a[u]);
        return ;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u) ; update(id*2+1,mid+1,r,u);
    st[id]=merge(st[id*2],st[id*2+1]);
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        char x; cin>>x;
        a[i]=x-'0';
    }
    build(1,1,n);
    for(int i=1;i<=q;++i)
    {
        string type;
        int x;
        cin>>type;
        if(type[0]=='s')
        {
            cin>>x;
            update(1,1,n,x);//for(int o=1;o<=n;++o) cout<<a[o];cout<<endl;
        }
        else
        {
            cout<<max({st[1].n00,st[1].n01,st[1].n11})<<'\n';
        }
    }
    return 0;
}
