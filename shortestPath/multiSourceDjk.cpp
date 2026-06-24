// dijkstra's algorithm for shortest path
// heart of dijkstra : always process node with the smallest distance

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


int main(){

    cout << "enter number of nodes: ";
    int n; cin >> n;
    cout << endl;
    cout << "enter number of edges: ";
    int m; cin >> m;
    cout << endl;


    map<int, vector<pair<int,int>>> adj;
    vi nodes;

    cout << "Take inputs in this order ( u, v, weight) : " << endl;

    for(int i=0; i < m; i++){
        int u, v, weight; 
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});

        nodes.push_back(u);
        nodes.push_back(v);
    }
    
    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    map<int, int> dist;

    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;

    for(int node : nodes){
        dist[node] = INT_MAX;
    }

    cout << "Enter the number of sources : " ;
    
    cout << endl;
    int k; cin >> k ;
    while(k--){
        int source; cin >> source;
        dist[source] = 0;
        pq.push({0, source});
    }

    while(!pq.empty()){
        auto [a,b] = pq.top(); // a for distance, b for node
        pq.pop();

        if(a > dist[b]) continue;

        for(auto &[v, w] : adj[b]){
            if(dist[b] + w < dist[v]){
                dist[v] = dist[b] + w;

                pq.push({dist[v], v});
            }
        }
    }

    for(int node : nodes){
        if(dist[node] == INT_MAX) cout << node << " : unreacheable" << endl;
        else cout << node << " : " << dist[node] << endl;
    }
}