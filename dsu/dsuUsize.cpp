/*  
Theory: 
dsu means Disjoin set union. 
dsu means partition of a set.
DSU detects cycle when adding an edge between already connected nodes
union by size =====> GOAL =====>  Tree joto kom height toto bhalo 
union by size = = small-> big
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int parent[N];
// int rankv[N];
int size[N];

int findset(int u){
    if(parent[u] == u) return u;
    return parent[u] = findset(parent[u]);
}

void union_set(int u, int v){
    u = findset(u);
    v = findset(v);

    if(u != v){
        if(size[u] > size[v]){
            parent[v] = u;
            size[u] += size[v];
        }
        else {
            parent[u] = v;
            size[v] += size[u];
        }
    }
}
int main(){

    int n; cin >> n; // n for nodes;

    for(int i = 0; i < n; i++){
        int a; cin >> a;

        parent[a] = a;
        // rankv[a] = 0;
        size[a] = 1;
    }

    int m; cin >> m; // m for edges

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        if(findset(u) == findset(v)) cout << "Cycle detected at : " << u << " and " << v << endl;
     
        else union_set(u,v);
    }


}