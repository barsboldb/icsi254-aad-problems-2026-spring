#include<bits/stdc++.h>
using namespace std;

const int N = 2e5, M = 2e5;

vector<vector<int> > adj;
vector<bool> vis;
vector<bool> color;

void dfs(int node, bool col){

    vis[node] = true;
    color[node] = col;
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(i, col ^ 1);
        }
    }

}

int main(){

    int n, m; cin >> n >> m;

    adj.assign(n, vector<int>());
    vis.assign(n, false);
    color.assign(n, 0);

    for(int i = 0;i < m;i++){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    for(int i = 0;i < n;i++)
        if(!vis[i])
            dfs(i, 0);

    for(int i = 0;i < n;i++){

        for(auto j : adj[i]){

            if(color[i] == color[j]){
                // Хэрэв граф нь bipartite биш бол.
                cout << "IMPOSSIBLE\n";
                return 0;
            }

        }

    }

    // Хэрэв граф нь bipartite мөн бол жишээ нэг будалт.
    
    for(int i = 0;i < n;i++){
        cout << 1 + color[i] << ' ';
    }
    cout << '\n';
}