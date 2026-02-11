#include <bits/stdc++.h>
using namespace std;
#define int             long long
#define pii             pair<int, int>
#define FOR(i,a ,b)      for(int i=a; i < b; i++)
#define ROF(i, a, b)      for(int i = a; i >= b; i--)
#define all(x)              x.begin(), x.end()
#define ff first
#define ss second
template<typename T, typename U>
ostream& operator<<(ostream &os, pair<T, U> p)
{
    return os << "(" << p.first << "," << p.second << ")";
}
template<typename T>
void print(T v, int lim = 1e9)
{
    for(auto x : v)
        if(lim-- > 0) cout << x << " ";
    cout << endl;
}

const int MOD = 1e9 + 7;
const int INF = 1e18;


void solve(){

    int n; cin >> n; 
    vector<int> t(n);
    for(int &i : t) cin >> i;

    vector<vector<int>> dp(n + 10, vector<int>(3, 0));

    dp[0][1] = t[0];
    // dp[0][0] = t[0];

    FOR(i, 1, n){
        dp[i][1] = dp[i - 1][0] + t[i];
        dp[i][2] = dp[i - 1][1] + t[i];
        dp[i][0] = max({dp[i - 1][2], dp[i - 1][1], dp[i - 1][0]}); 
    }

    cout << max({dp[n - 1][2], dp[n - 1][1], dp[n - 1][0]});



}
signed main()
{
    int test = 1; 
    // cin >> test;
    while(test--){
        solve();
    }
}
