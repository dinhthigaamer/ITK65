#include<bits/stdc++.h>
using namespace std;

#define MAX 500010
#define ll long long 

int N;
ll A[MAX], B[MAX], C[MAX];

int main()
{
    //freopen("file.inp", "r", stdin);
    //freopen("file.out", "w", stdout);
    
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> A[i];
    for(int i = 1; i <= N; ++i) cin >> B[i];

    for(int i = 1; i <= N; ++i) C[i] = A[i] - B[i];
    sort(C + 1, C + N +1, greater<ll>());

    ll sum = 0;

    for(int i = 1; i <= N; ++i)
    {
        sum += 1ll * C[i] * i;
        sum += (N + 1) * B[i];
    }

    cout << sum << endl;
    return 0;   
}