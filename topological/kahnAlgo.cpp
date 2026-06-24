// indegree = ekta node e kota gula node dukhtese shei number tai hocche oi node er indegreee
// kahn's algo works only if at least one node has indegree 0
// if you can't process all nodes, then graph has a cycle
// Cycle = nodes waiting for each other → nobody becomes free

#include<bits/stdc++.h>
#include<bit> 

using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n ;
    int m; cin >> m ;

    vector<int> nodes;

    map<int, vi> adj;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        adj[u].push_back(v);

        nodes.push_back(u);
        nodes.push_back(v);
    }

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    map<int, int> indegree;

    for(int i : nodes){
        indegree[i] = 0;
    }

    for(auto &i : adj){
        int u = i.first;

        for(int a : adj[u]){
            indegree[a]++;
        }
    }

    queue<int> q;

    for(int i : nodes){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vi topo;

    while(!q.empty()){

        int current = q.front();
        q.pop();

        topo.push_back(current);

        for(int a : adj[current]){
            indegree[a]--;

            if(indegree[a] == 0){
                q.push(a);
            }
        }
    }


    if(topo.size() != nodes.size()){
        cout << "Cycle exists\n";
    } else {
        cout << "Topological order: ";
        for(int x : topo){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}