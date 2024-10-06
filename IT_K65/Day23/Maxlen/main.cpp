#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
#define SIZE 320

class sqrt_decomp{
public:
      int n,a[MAX];
      int nB,Bs,B[MAX],st[MAX]={0},fn[MAX]={0};
      int L[SIZE][MAX]={0},R[SIZE][MAX]={0};
      int pos[MAX]={0};

      void rrh(){
           vector<int> rar;
           for(int i=1;i<=n;++i) rar.push_back(a[i]);
           sort(rar.begin(),rar.end());
           rar.erase(unique(rar.begin(),rar.end()),rar.end());
           for(int i=1;i<=n;++i)
             a[i]=lower_bound(rar.begin(),rar.end(),a[i])-rar.begin()+1;
      }

      sqrt_decomp(int N,int A[]){
           n=N;
           for(int i=1;i<=n;++i) a[i]=A[i];
           rrh();

           Bs=sqrt(n) ; nB=(n-1)/Bs+1;
           for(int i=1;i<=nB;++i){
               st[i]=fn[i-1]+1;
               fn[i]=min(n,st[i]+Bs-1);
               for(int j=st[i];j<=fn[i];++j) B[j]=i;
           }

           for(int j=1;j<=nB;++j){
               for(int i=fn[j];i>=1;--i){
                    pos[a[i]]=max(pos[a[i]],i);
                    L[j][i]=L[j][i+1];
                    L[j][i]=max(L[j][i],pos[a[i]]-i);
               }
           }

           for(int i=1;i<=n;++i) pos[i]=n+1;
           for(int j=nB;j>=1;--j){
               for(int i=st[j];i<=n;++i){
                    pos[a[i]]=min(pos[a[i]],i);
                    R[j][i]=R[j][i-1];
                    R[j][i]=max(R[j][i],i-pos[a[i]]);
               }
           }
      }

      int query(const int& l,const int& r){
           int res=max(L[B[r]-1][l],R[B[l]+1][r]);//cerr<<res<<endl;
           for(int i=l;i<=fn[B[l]];++i) pos[a[i]]=0;
           for(int i=st[B[r]];i<=r;++i) pos[a[i]]=0;

           for(int i=l;i<=min(r,fn[B[l]]);++i){
               if(pos[a[i]]!=0) res=max(res,i-pos[a[i]]);
               else
               pos[a[i]]=i;
           }
           if(B[l]!=B[r]){
               for(int i=st[B[r]];i<=r;++i){
                   if(pos[a[i]]!=0) res=max(res,i-pos[a[i]]);
                   else
                   pos[a[i]]=i;
               }
           }
           return res;
      }
};

int n,Q;
int a[MAX];
sqrt_decomp *sqd;

int main(){
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n>>Q;
    for(int i=1;i<=n;++i) cin>>a[i];

    sqd=new sqrt_decomp(n,a);

    /*for(int j=1;j<=sqd->nB;++j){
        for(int i=1;i<=n;++i) cout<<sqd->R[j][i]<<' ';
        cout<<endl;
    }*/
    for(int l,r,i=1;i<=Q;++i){
        cin>>l>>r;
        cout<<sqd->query(l,r)<<'\n';
    }
    return 0;
}