#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct DSU {
    map<T, T> parent;

    map<T, int> rankv;

    // Find with path compression
    T find_set(T x){
        if(parent.find(x) == parent.end()){
            parent[x] = x; // lazy initialization
            rankv[x] = 0;
        }

        if(parent[x] == x) return x;

        return parent[x] = find_set(parent[x]);
    }

    // Union
    void union_set(T a, T b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            // parent[b] = a;
            if(rankv[a] > rankv[b]){
                parent[b] = a;
            }
            else if(rank[b] > rank[a]) parent[a] = b;
            else {
                parent[a] = b;
                rank[b]++;
            }
        }
    }

    // Cycle detection (for edge u-v)
    bool is_cycle(T u, T v){
        return find_set(u) == find_set(v);
    }
};

int main(){

    DSU<string> dsu;  // change type here: int / char / string

    int m;
    cin >> m; // number of edges

    while(m--){
        string u, v;
        cin >> u >> v;

        if(dsu.is_cycle(u, v)){
            cout << "Cycle detected between " << u << " and " << v << "\n";
        } else {
            dsu.union_set(u, v);
        }
    }

    return 0;
}