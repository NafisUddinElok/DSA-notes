#include<bits/stdc++.h>
#include<bit> // for bit operations always use unsigned integers
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;

map<int, int> dist; // to store distance of each node from the start node 

void bfs(int startNode, map<int, vector<int>>& adj, map<int, bool>& visited){

    queue<int> q;

    q.push(startNode);
    visited[startNode] = true; 

    
    while(!q.empty()){

        int current = q.front();
        cout << current << " ";
        q.pop();

        for(int neighbor : adj[current]){
            if(visited[neighbor] != true){
                visited[neighbor] = true; // mark as visited when pushing to queue to avoid multiple pushes of the same node
                
                dist[neighbor] = dist[current] + 1; // update the distance of the neighbor node from the start node
                
                q.push(neighbor);
            }
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n; cin >> n; // node count
    int e; cin >> e; // edge count


    map<int, vector<int>> adj;
    map<int, bool> visited;
    vector<int> nodes; // to keep track of all unique nodes


    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

        nodes.push_back(u);
        nodes.push_back(v);
    }

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());



    // calculate distance of each node from the start node using bfs(for connected and disconnected graph)s
    int startNode; cin >> startNode; 
    dist[startNode] = 0; 
    bfs(startNode, adj, visited);



    // // for disconnected graph, we need to call bfs for each unvisited node to cover all components of the graph
    // for(int node : nodes){
    //     if(visited[node] != true){
    //         bfs(node, adj, visited);
    //     }
    // }

    // printing the distance of each node from the start node
    cout << "\nDistances from the start node:\n";
    for(int node : nodes){
        if(visited[node]){
            cout << "Node " << node << ": " << dist[node] << endl;
        }
        else {
            cout << "Node " << node << ": Unreachable from the start node" << endl;
        }
    }



    return 0;
}