#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;

vector<vector<int> > adj(MAXN);
vector<bool > vis(MAXN);

bool dfs(int node, int p){

    vis[node] = true;

    for(auto i : adj[node]){
        if(i == p)
            continue;
        if(vis[i])
            return 1;
        if(dfs(i, node))
            return 1;
    }
    return 0;   
}

int main(){

    int n, m;
    bool type;
    cin >> n >> m;

    for(int i = 0;i < m;i++){

        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);

    }

    if(dfs(0, -1)){
        cout << "Cycle found." << '\n';
        return 0;
    }

    cout << "No cycle found." << '\n';
}