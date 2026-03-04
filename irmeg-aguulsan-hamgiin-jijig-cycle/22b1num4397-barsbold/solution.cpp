#include<bits/stdc++.h>
using namespace std;
using edge = pair<int, int>;
void read_graph(int &n, int &m, int &dir, vector<vector<edge>> &adj)
{
    string line;
    getline(cin, line);
    istringstream in(line);
    dir = 0;
    if(!(in >> n) || !(in >> m))
    {
        cerr << "usage |V| |E|\n";
        exit(0);
    }
    if(!(in >> dir)) 
    {
        cerr << "Chiglel ugugdugui(default=undirected)\n";
    }
    cin >> ws;
    adj.assign(n + 1, {});
    int weighted = 1;
    for(int it = 0; it < m; it++)
    {
        getline(cin, line);
        in = istringstream(line);
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
        if(!dir) adj[v].push_back({u, w});
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
    vector<int> par((int)adj.size(), -1);
    vector<bool> vis((int)adj.size());
    q.push(src);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        vis[u] = true;
        for(auto [to, w] : adj[u])
        {
            if(vis[to]) continue;
            par[to] = u;
            //cout << u << ' ' << to << endl;
            dist[to] = dist[u] + w;
            q.push(to);
        }
    }
    //for(auto x : par) cout << x << ' '; cout << endl;

    return {dist, par};
}
vector<int> find_path(vector<int> par, int src, int dst)
{
    vector<int> path;
    int u;
    for(u = dst; u != -1; u = par[u])
    {
        //cout << u << ' ' << par[u] << endl;
        path.push_back(u);
    }
    if(path.back() != src) return {};
    reverse(path.begin(), path.end());
    return path;
}
void rem_edge(vector<vector<edge>> &adj, int u, int v, int w = 1)
{
    auto it = find(adj[u].begin(), adj[u].end(), pair(v, w));
    if(it != adj[u].end()) adj[u].erase(it);
}
int main()
{
    int n, m, dir;
    vector<vector<edge>> adj;
    read_graph(n, m, dir, adj);
    int s, t, w = 1; cin >> s >> t >> w;
    rem_edge(adj, s, t, w);
    if(!dir) rem_edge(adj, t, s, w);
    bfs_result res = bfs(adj, s);
    auto [dist, par] = res;
    auto path = find_path(par, s, t);
    if(!path.size()) 
    {
        cout << "No cycle\n";
        return 0;
    }
    cout << path.size() << '\n';
    for(int u : path) cout << u << ' ';
    cout << '\n';
}
