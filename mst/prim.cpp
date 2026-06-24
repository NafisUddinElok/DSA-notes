#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    fast_io;

    // int n; cin >> n; // nodes
    int m; cin >> m; // edges

    map<int, vector<pair<int,int>> > adj;

    for(int i =0; i<m; i++){
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    map<int, bool> visited;

    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>
                    > pq;
    
    int start; cin >> start;
    pq.push({0, start}); // 0(log n)

    int mst_cost = 0;

    while(!pq.empty()){

        auto[wt,u] = pq.top();

        pq.pop(); // o(log n)

        if(visited[u] == true) continue;

        visited[u] = true;
        mst_cost += wt;

        for(auto [v, wt] : adj[u]){
            // if(visited[v] == true) continue;
            if(!visited[v]) {
                pq.push({wt, v});
            }
        }
    }
    cout << "mst cost : " << mst_cost << endl;
    return 0;
}