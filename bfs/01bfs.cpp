// the heart of 0-1 bfs : dequeue + distance array
// 


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
    deque<int> dq;

    for(int node : nodes){
        dist[node] = INT_MAX;
    }

    cout << "Enter the source node : " ;
    int source; cin >> source;
    cout << endl;
    dist[source] = 0;
    dq.push_front(source);

    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();

        for(auto &[v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;

                if(w == 0) dq.push_front(v);
                else dq.push_back(v); // for weight = 1
            }
        }
    }

    for(int node : nodes){
        if(dist[node] == INT_MAX) cout << node << " : unreacheable" << endl;
        else cout << node << " : " << dist[node] << endl;
    }





}