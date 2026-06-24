// Every edge connects two different groups
// bipartite graph = graph is 2 colorable
// only cycle length matters, not total edges 

// 🧠 So full truth
// Graph type	    Bipartite?
// No cycle	        yes
// Even cycle	    yes
// Odd cycle	    no

// bipartite = no odd cycle ( cycle length should not be odd)
// two set partition, 2-colorable, no odd cycle ------> Bipartite conditions


#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m; cin >> n >> m; // n for nodes, m for edges

    map<int, vector<int>> adj;
    vector<int> nodes;

    for(int i= 0; i < m; i++){
        int u, v; cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

        nodes.push_back(u);
        nodes.push_back(v);
    }


    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    map<int, int> color; // -1 for unvisited, 0/1 = color
    
    for(int node : nodes){
        color[node] = -1;
    }

    bool isBipartite = true;
    
    for(int start : nodes){
        
        if(color[start] != -1) continue; // already colored so skip. won't change the previous color

        color[start] = 0; // unvisited one will be colored 0 

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]){
                    isBipartite = false;
                    break;
                }
            }
        }
    }

    if(isBipartite) cout << "Bipartite" << endl;
    else cout << "Not Bipartite" << endl;

    return 0;
}