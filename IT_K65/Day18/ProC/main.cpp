#include<bits/stdc++.h>
using namespace std;

#define MAX 1000010
#define ll long long

class rectangle{
public:
    ll x,y,a;

    bool operator<(const rectangle&other)const{
        if(x==other.x) return (y>other.y);
        return (x < other.x);
    }
};

class Line{
public:
    ll X,Y;
};

int n;
int p=1,sz=1;
long double in[MAX];
Line st[MAX];
rectangle rec[MAX];
ll dp[MAX];

int check(Line A,Line B,Line C){
    if(A.X == C.X) return 0; // can't intersect
    if(sz==1) return 1;
    // ax+b = cx+d => x = (d-b)/(a-c)
    long double X2 = (long double)(B.Y-A.Y)/(A.X-B.X);
    long double X1 = (long double)(C.Y-A.Y)/(A.X-C.X);

    if(X1<=X2){
        return 0;
    }
    return 1;
}

long long Find(long long x){
    while(p<sz && st[p+1].X*x+st[p+1].Y >= st[p].X*x+st[p].Y) ++p;
    return st[p].X * x + st[p].Y;
}

void Insert(ll x,ll y){
    Line A={x,y};
    while(sz>=1 && !check(A,st[sz-1],st[sz])) --sz;
    p=min(p,sz);

    ++sz;
    st[sz]=A;
}

void checktest(){
     for(int i=2;i<=n;++i){
        if(!((rec[i-1].x < rec[i].x) && (rec[i].y < rec[i-1].y))){
            cerr<<rec[i-1].x<<' '<<rec[i-1].y<<' '<<rec[i-1].a<<endl;
            cerr<<rec[i].x<<' '<<rec[i].y<<' '<<rec[i].a<<endl;
        }
        assert((rec[i-1].x < rec[i].x) && (rec[i].y < rec[i-1].y) && (rec[i].a <= rec[i].x*rec[i].y));
     }
}

int main(){
   // freopen("file10.inp","r",stdin);
  //    freopen("file10.out","w",stdout);
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>rec[i].x>>rec[i].y>>rec[i].a;
    }

    sort(rec+1,rec+n+1);
    checktest();

    dp[0]=0;
    Insert(0,0);

    for(int i=1;i<=n;++i){
        //for(int j=1;j<=sz;++j) cout<<st[j].X<<' ';cout<<endl;
        dp[i] = rec[i].x * rec[i].y - rec[i].a;
        ll tmp=Find(-rec[i].y);
        dp[i] = max(dp[i],tmp + (rec[i].x * rec[i].y - rec[i].a));
        Insert(rec[i].x,dp[i]);
    }
    cout<<*max_element(dp+1,dp+n+1)<<endl;
    return 0;
}
