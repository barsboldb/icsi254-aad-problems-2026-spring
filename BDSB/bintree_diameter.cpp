#include<bits/stdc++.h>
#define left first
#define right second
#define height first
#define diameter second
using namespace std;

const int N = 2e5, M = 2e5;

vector<int> par;
vector<pair<int,int> > child;

pair<int,int> rec(int node){
    if(child[node].left == -1 and child[node].right == -1){ return {0, 0}; }

    pair<int,int> tmp1 = {-1, -1}, tmp2 = {-1, -1};

    if(child[node].left != -1) tmp1 = rec(child[node].left);
    if(child[node].right != -1) tmp2 = rec(child[node].right);

    return {
        max(tmp1.height, tmp2.height) + 1,
        ((tmp1.height != -1) ? tmp1.height : 0) + 
        ((tmp2.height != - 1) ? tmp2.height : 0) + 
        (tmp1.height != -1) + (tmp2.height != -1)
    };
}

int main(){

    int n; cin >> n;

    par.assign(n, 0);
    child.assign(n, {-1, -1});

    int root;

    for(int i = 0;i < n;i++){
        int p; cin >> p;

        if(p == -1){
            root = i;
            continue;
        }

        par[i] = p - 1; 

        if(child[p - 1].left == -1) child[p - 1].left = i;
        else child[p - 1].right = i;

    }

    cout << rec(root).diameter << '\n';

}