#include<bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define ll long long 
const ll mod = 1e9+7;

int n;
ll dp[MAX];

int main()
{
    freopen("file.inp", "r", stdin);
    freopen("file.out", "w", stdout);
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    cin >> n;
    dp[1] = 1;

    for(int i = 2; i <= n; ++i)
    {
        dp[i] = (((2*i*i%mod) - i + mod*mod)%mod) * dp[i-1]%mod;
    }

    cout << dp[n] << endl;
    return 0;
}