#include<bits/stdc++.h>
using namespace std;

#define MAX 200005
#define Task "file"
const int MOD=1e9+7;

int n,k;
string s;
int dp[MAX][11];
int last[29];

void File()
{
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
}

int add(int A,int B)
{
    A+=B;
    if(A>=MOD) A-=MOD;
    if(A<0) A+=MOD;
    return A;
}

void solve()
{
    cin>>n>>k;
    cin>>s;
    s=" "+s;

    dp[0][0]=1;  
    memset(last,-1,sizeof(last));

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=k;++j)
        {
            dp[i][j]=add(dp[i][j],dp[i-1][j]);
            if(j>0) dp[i][j]=add(dp[i][j],dp[i-1][j-1]);
            
            if(last[s[i]-'a']!=-1 && j-(i-last[s[i]-'a'])>=0)
            {
                dp[i][j]=add(dp[i][j],-dp[last[s[i]-'a']-1][j-(i-last[s[i]-'a'])]);
            }
        }
        last[s[i]-'a']=i;
    }
    /*for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=k;++j) cout<<dp[i][j]<<' ';
        cout<<endl;
    }*/
    cout<<dp[n][k]<<endl;
}

int main()
{
    //File();
    solve();

    return 0;
}
/*
7 2
myyjyvb
*/
