#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;



map<int, vector<int>> adj;

map<int,int> parent;
map<int,int> depth;
map<int,int> subtree;

void dfs(int n, int p){ // n for node, p for parent
    parent[n] = p;
    subtree[n] = 1;

    for(int v : adj[n]){

        if(v == p) continue;

        // subree[n] += subtree[v];
        // parent[v] = n;

        depth[v] = depth[n] + 1;
        dfs(v, n);

        subtree[n] += subtree[v];
    }
}


int main() {
    fast_io;

    // tree
    int nodes; cin >> nodes;
    int m; cin >> m;
    // even though for tree : m = nodes - 1; its okay if we calculate like this

    
    for(int i =0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    

    int root; cin >> root;
    depth[root] = 0;

    dfs(root, -1);



    return 0;
}