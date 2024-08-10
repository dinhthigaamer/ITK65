#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
string A,B;
int D,k;
ll f[17][11][17][2][2][2];

int gt(char x)
{
    return x-'0';
}

long long dp(int pos,int val,int cnt,int nonzero,int ok1,int ok2)
{
    //ok1 :A , ok2:B
    if(pos==n) return cnt<=k;
    if(cnt>k) return 0;

    ll &x=f[pos][val][cnt][nonzero][ok1][ok2];
    if(x!=-1) return x;
    x=0;

    for(int i=gt(A[pos])*(ok1^1);i<=max(gt(B[pos]),9*ok2);++i)
    {
        int newok1=ok1 , newok2=ok2 , newcnt=cnt;
        newok1|=(i>gt(A[pos]));
        newok2|=(i<gt(B[pos]));
        if(nonzero) newcnt+=(abs(i-val)<=D);
        x+=dp(pos+1,i,newcnt,nonzero|(i>0),newok1,newok2);
    }
    return x;
}

int main()
{
    cin>>A>>B>>D>>k;
    memset(f,-1,sizeof(f));
    n=B.size();
    while(A.size()<n) A="0"+A;
    memset(f,-1,sizeof(f));
    cout<<dp(0,0,0,0,0,0)<<endl;
    return 0;
}
