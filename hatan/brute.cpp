#include<bits/stdc++.h>
using namespace std;
vector<int> adj[25];
bool vis[25];
int a[25];
int ans = 0;
int goal;
void dfs(int u, int x)
{
    if(a[u] >= x) x /= 2;
    if(x == 0) return;
    if(u == goal) ans = max(ans, x);
    //cout << u << " " << x << " " << a[u] << endl;
    vis[u] = true;
    for(int v : adj[u])
    {
        if(vis[v]) continue;
        dfs(v, x);
    }
    vis[u] = false;
}
int main()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x; cin >> x;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    goal = n;
    dfs(1, x);
    cout << ans << "\n";
    
}