#include<bits/stdc++.h>
#include<bit> // for bit operations always use unsigned integers
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;

/****************************************************
 *                                                  *
 *     C O N N E C T E D   C O M P O N E N T S      *
 *                                                  *
 ****************************************************/

 int main(){
    int n, m; cin >> n >> m;
    // n = rows, m = columns

    map<int, vector<int>> graph;

    for(int i= 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool hascycle = false; // to check if the graph has a cycle or not

    map<int, bool> visited;
    map<int, int> parent;

    function<void(int)> dfs = [&](int node){
        visited[node] = true;

        for(int nei : graph[node]){
            if(!visited[nei]) {
                parent[nei] = node;
                dfs(nei);
            }
            else if(nei != parent[node]) hascycle = true; // if the neighbor is visited and is not the parent of the current node, then there is a cycle in the graph
        }
    };

    int connected_components = 0;

    for(auto node : graph){
        if(!visited[node.first]){
            connected_components++;
            parent[node.first] = -1; // set the parent of the starting node of each component to -1
            dfs(node.first);
        }
    }

    cout << "Number of connected components: " << connected_components << endl; 

    if(hascycle){
        cout << "The graph has a cycle." << endl;
    } else {
        cout << "The graph does not have a cycle." << endl;
    }
    

 }