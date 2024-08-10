//avocado
#include<bits/stdc++.h>
using namespace std;

#define MAXN 50005
#define MAXM 100005
 
int n,m;
vector<int> g[MAXM];
pair<int,int> edge[MAXM];
int par[MAXM];
int inMST[MAXM];
int child[MAXM],parent[MAXM];
int in[MAXM],cnt;
int head[MAXM],h[MAXM];

class segment_tree
{
public:
    int L,R,Mid;
    int val,lazy;
    segment_tree *left, *right;

    segment_tree(int l,int r)
    {
        L=l; R=r; Mid=((l+r)/2);
        val=0; lazy=-1;
        if(L==R) return ;
        left = new segment_tree(L,Mid);
        right = new segment_tree(Mid+1, R);
    }

    void down()
    {
        if(lazy==-1) return ;
        if(left != NULL)
        {
            left->val = lazy*(Mid-L+1);
            left->lazy = lazy;
        }
        if(right != NULL)
        {
            right->val = lazy*(R-Mid);
            right->lazy = lazy;
        }
        lazy = -1;
    }

    void up(int u,int v,int value)
    {
        if(u>R || v<L) return ;
        if(u<=L && R<=v)
        {
            val = (R-L+1)*value;
            lazy = value;
            return ;
        }
        down();
        left->up(u,v,value);
        right->up(u,v,value);
        val = left->val + right->val;
    }

    int get(int u,int v)
    {
        if(u>R || v<L) return 0;
        if(u<=L && R<=v) return val;
        down();
        return left->get(u,v)+right->get(u,v);
    }
};

segment_tree *tree;

int Find(int u)
{
    if(par[u]<0) return u;
    return par[u]=Find(par[u]);
}

int Joint(int u,int v)
{
    u=Find(u); v=Find(v);
    if(u==v) return 0;
    
    if(par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;

    return 1;
}

void reset()
{
    cnt=0;
    fill(par+1,par+n+1,-1);
    //for(int i=1;i<=n;++i) par[i]=-1;
    fill(parent+1,parent+n+1,0);
    //for(int i=1;i<=n;++i) parent[i]=0;
    fill(head+1,head+n+1,0);
    //for(int i=1;i<=n;++i) head[i]=0;
    fill(h+1,h+n+1,0);
    //for(int i=1;i<=n;++i) h[i]=0;
    for(int i=1;i<=n;++i) g[i].clear();
    fill(inMST+1,inMST+m+1,0);
    //for(int i=1;i<=m;++i) inMST[i]=0;
    fill(child+1,child+n+1,0);
}

void makeTree()
{
    reset();
    tree = new segment_tree(1,n);

    for(int i=1;i<=m;++i)
    {
        auto [u,v] = edge[i];
        //cerr<<u<<' '<<v<<endl;
        if(Joint(u,v))
        {
            inMST[i]=1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    } 
}

void dfs(int u,int cha)
{
    //cerr<<u<<endl;
    child[u]=1;
    parent[u]=cha;
    int imax=0, smax=0;

    for(int i=0;i<(int)g[u].size();++i) if(g[u][i]!=cha)
    {
        int v=g[u][i];
        dfs(v,u);
        child[u]+=child[v];
        if(child[v]>smax)
        {   
            smax=child[v];
            imax=i;
        } 
    }
    
    if(g[u].size()>0) swap(g[u][0],g[u][imax]);
}

void hld(int u)
{
    in[u]=++cnt;

    for(int v:g[u]) if(parent[u]!=v)
    {
        if(v==g[u][0])
        {
            head[v]=head[u];
            h[v]=h[u];
        }
        else 
        {
            head[v]=v;
            h[v]=h[u]+1;
        }
        hld(v);
    }
}

int LCA(int u,int v)
{
    if(h[v]<h[u]) swap(u,v);
    while(h[v]>h[u])
    {
        v=parent[head[v]];   
    }
    while(head[u]!=head[v])
    {
        u=parent[head[u]];
        v=parent[head[v]];
    }
    if(in[u]<=in[v]) return u;
    return v;
}

void up(int u,int v,int val)
{
    int ch = LCA(u,v);
    while(head[u]!=head[ch])
    {
        tree->up(in[head[u]], in[u], val);
        u=parent[head[u]];
    }
    tree->up(in[ch]+1, in[u], val);

    while(head[v]!=head[ch])
    {
        tree->up(in[head[v]], in[v], val);
        v=parent[head[v]];
    }
    tree->up(in[ch]+1, in[v], val);
}

int query(int u,int v)
{
    int res=0;
    int ch = LCA(u,v);
    while(head[u]!=head[ch])
    {
        res += tree->get(in[head[u]], in[u]);
        u=parent[head[u]];
    }
    res += tree->get(in[ch]+1, in[u]);

    while(head[v]!=head[ch])
    {
        res += tree->get(in[head[v]], in[v]);
        v=parent[head[v]];
    }
    res += tree->get(in[ch]+1, in[v]);

    return res;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        ++u; ++v;
        edge[i]={u,v};
    }
    makeTree();
    //cerr<<1<<endl;
    for(int i=1;i<=n;++i) if(parent[i]==0)
    {
        dfs(i,i);
        head[i]=i;
        hld(i);
    }

    int bridge = 0;

    for(int i=1;i<=m;++i)
    {
        auto [u,v] = edge[i];
        if(inMST[i])
        {
            ++bridge;
            up(u,v,1);
        }
        else 
        {
            bridge -= query(u,v);
            up(u,v,0);
        }
        cout<<bridge<<'\n';
    }
    free(tree);
    /*cout<<1<<endl<<2<<endl<<3<<endl<<1<<endl<<2<<endl;
    for(int i=1;i<=5;++i) cout<<0<<endl;*/

}

void File()
{
    freopen("file.inp","r",stdin);
    freopen("file.out","w",stdout);
}

int main()
{
    //File();
    int test;
    cin>>test;

    while(test--)
    {
        solve();
    }

    return 0;
}
