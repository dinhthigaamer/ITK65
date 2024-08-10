#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll a[105],b[105];
ll pre[105],suf[105];

void solve(){
     cin>>n;
     for(int i=1;i<=n;++i) cin>>a[i];

     for(int i=0;i<=57;++i)
     {
         int bit0=0 , bit1=0;
         for(int j=1;j<=n;++j)
         {
            bit0=max(bit0,(int)(((a[j]>>i)&1)==0));
            bit1=max(bit1,(int)(((a[j]>>i)&1)==1));
         }
         if(bit0 && bit1)
         {
            cout<<((1ll)<<(i+1))<<'\n';
            break;
         }
     }
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