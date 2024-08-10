#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(A) (int)A.size()

ll m,k;
string s1,s2;
ll f[19][19][2][2][2];

void convert(string& s,ll x){
     s.clear();
     while(x){
        s=char(x%10+'0')+s;
        x/=10;
     }
}

ll cal(int pos1,int pos2,int nonzero,int ok1,int ok2){
    if(pos2==sz(s2)){
        //cout<<pos1<<' '<<pos2<<' '<<nonzero<<' '<<ok1<<' '<<ok2<<endl;
        return nonzero;
    }
    ll* x=&f[pos1][pos2][nonzero][ok1][ok2];
    if((*x)!=-1) return (*x);

    (*x)=0;
    for(int i=0;i<=9;++i){
        if(i==0 && nonzero==0) (*x)+=cal(pos1,pos2+1,0,0,1);
        else {
            if(ok2==0 && i>(s2[pos2]-'0')) break;
            if(ok1==0 && i>(s1[pos1]-'0')) break;
            (*x)+=cal(pos1+1,pos2+1,1,ok1|(i<(s1[pos1]-'0')),ok2|(i<(s2[pos2]-'0')));
        }
    }
    return (*x);
}

int check(ll &ans,const ll&x){
    memset(f,-1,sizeof(f));
    convert(s2,x);
    string pattern=s1;
    while(sz(s1)<sz(s2)) s1=s1+"/";
    ll pos=cal(0,0,0,0,0); //cout<<x<<' '<<pos<<' '<<s1<<endl;
    if(pos==m) ans=x;
    s1=pattern;

    return pos>=m;
}

void solve(){
     cin>>k>>m;
     convert(s1,k);

     ll low=k , high=2e18 , ans=0;

     while(low<=high){
         ll mid=(low+high)/2;
         if(check(ans,mid)){
              high=mid-1;
         }
         else {
              low=mid+1;
         }
     }

     cout<<ans<<'\n';
}

int main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
