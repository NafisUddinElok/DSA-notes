// mst means minimum spanning tree. 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

struct edge{
    int u, v, w;
};
int parent[N];
int sz[N];

int findset(int u){
    if(parent[u] == u) return u;
    else return parent[u] = findset(parent[u]);
}
void union_set(int u, int v){
    u = findset(u);
    v = findset(v);

    if(u != v){
        if(sz[u] < sz[v]){
            parent[u] = v;
            sz[v] += sz[u];
        }
        else{
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
}

int main(){

    int n, m; cin >> n >> m; // n for nodes, m for edges

    vector<edge> edges;

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        parent[a] = a;
        sz[a] = 1;
    }

    sort(edges.begin(), edges.end(), [](edge a, edge b){
        return a.w < b.w;
    });

    int mst_cost = 0;
    vector<edge> mst_edges;

    for(auto &e : edges){
        int u = e.u;
        int v = e.v;
        int w = e.w;

        if(findset(u) != findset(v)){
            union_set(u, v);
            mst_cost += w;

            mst_edges.push_back(e);
        }
    }

    cout << " mst cost : " << mst_cost << endl;

    cout << "edges in mst : " << endl;
    for(auto &e : mst_edges){
        cout << e.u << " " << e.v << " " << e.w << endl;
    }




}

/// generic dsu => generic krushkal 