#include<bits/stdc++.h>
#include<bit> // for bit operations always use unsigned integers
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;

// directed cycle detection using recursion stack and DFS

int main(){

    bool hascycle = false;
    map<int, bool> recStack;


    int n; cin >> n; // nodes
    int m; cin >> m; // edges

    map<int, vector<int>> graph;

    vector<int> nodes;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u); // for undirected graph

        nodes.push_back(u);
        nodes.push_back(v);
    }

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    map<int, bool> visited; 
    for(auto node : graph){
        visited[node.first] = false; // initialize all nodes as unvisited
        recStack[node.first] = false;
    }

    function<void(int)> dfs = [&](int node){
        visited[node] = true;
        recStack[node] = true;
        cout << node << " ";

        for(int neighbor : graph[node]){
            if(!visited[neighbor]) dfs(neighbor);
            else if(recStack[neighbor]==true) hascycle = true;
        }
        
        recStack[node] = false;
    };


    for(int node : nodes){
        if(!visited[node]){
            dfs(node);
            cout << endl;
        }
    }

    if(hascycle == true){
        cout << 
            "This graph has a cycle"
                << endl;;
    }
    else {
        cout << 
            "No cycle" 
            << endl;
    }

    


    

}