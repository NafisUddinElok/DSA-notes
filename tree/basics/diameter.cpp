#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;


map<int, vi> adj;


pair<int,int> dfs(int u, int p, int d){
    // u = current ndoe, p = parent, d = distance from start to current node
    pair<int,int> best = {d, u};

    for(int v : adj[u]){
        if(v == p) continue;
        
        best = max(best, dfs(v, u, d+1));
    }

    return best;
}

int main() {
    fast_io;

    int m; cin >> m;

    // map<int, vi> adj;
    vi nodes;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        nodes.push_back(u);
        nodes.push_back(v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    int start; cin >> start;

    auto [dist, farthest] = dfs(start, -1, 0);

    cout << "distance from the start to farthest : " << dist
        << " , fartheset node : " << farthest << endl;

    auto [diameter, b] = dfs(farthest, -1, 0);
    cout << "Diameter : " << diameter << " , nodes from " << farthest << " to " << b << endl;



    return 0;
}