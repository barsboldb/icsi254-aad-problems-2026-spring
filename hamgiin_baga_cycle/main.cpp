#include<bits/stdc++.h>
using namespace std;
struct edge { int to, w; };
void read_graph(int &n, int &m, vector<vector<edge>> &adj)
{
    if(!(cin >> n) || !(cin >> m))
    {
        cerr << "usage |V| |E|\n";
        exit(0);
    }
    cin >> ws;
    adj.assign(n + 1, {});
    int weighted = 1;
    for(int it = 0; it < m; it++)
    {
        string line;
        getline(cin, line);
        istringstream in(line);
        int u, v, w = 1;
        if(!(in >> u)) 
        {
            cerr << "Ehnii irmeg ugugdugui!\n";
            exit(0);
        }
        if(!(in >> v))
        {
            cerr << "2 doh irmeg ugugdugui!\n";
            exit(0);
        }
        if(!(in >> w))
            weighted = 0;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    if(!weighted)
    {
        cerr << "Zarim irmegiin jingiin medeelel ugugdugu(default = 1)\n";
    }
}
struct bfs_result
{
    vector<int> dist;
    vector<int> par;
};
bfs_result bfs(vector<vector<edge>> &adj, int src)
{
    queue<int> q;
    vector<int> dist((int)adj.size());
    vector<int> par((int)adj.size());
    vector<bool> vis((int)adj.size());
    q.push(src);
    par[src] = src;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        vis[u] = true;
        for(auto [to, w] : adj[u])
        {
            if(vis[to]) continue;
            par[to] = u;
            dist[to] = dist[u] + w;
            q.push(to);
        }
    }
    return {dist, par};
}
vector<int> find_path(vector<int> par, int src, int dst)
{
    vector<int> path;
    for(int u = dst; u != src; u = par[u])
        path.push_back(u);
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}
int main()
{
    int n, m;
    vector<vector<edge>> adj;
    read_graph(n, m, adj);
    int s, t, w = 1; cin >> s >> t >> w;
    bfs_result res = bfs(adj, s);
    auto [dist, par] = res;
    auto path = find_path(par, s, t);
    cout << dist[t] << '\n';
    for(int u : path) cout << u << ' ';
    cout << '\n';
}
