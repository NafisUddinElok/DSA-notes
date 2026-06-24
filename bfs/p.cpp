#include<bits/stdc++.h>
#include<bit> // for bit operations always use unsigned integers
using namespace std;


using u32 = uint32_t;
using u64 = uint64_t;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;

/** MULTI SOURCE BFS */

int main(){

    int n, m; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, -1)); 

    vector<pair<int, int>> sources; 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                sources.push_back({i, j});
                visited[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }


    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1}));
    queue<pair<int, int>> q;

    for(auto source : sources){
        q.push(source);
    }

    int dr[4] = {-1, 1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1}; 

    while(!q.empty()){
        pair<int, int> cell = q.front();
        
        q.pop();
        
        int r = cell.first;
        int c = cell.second;

        for(int i = 0; i < 4; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            bool boundarycondition = (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m); 
            
            if(boundarycondition && !visited[new_r][new_c] && grid[new_r][new_c] == 1){ 
                visited[new_r][new_c] = true;
                dist[new_r][new_c] = dist[r][c] + 1; 
                parent[new_r][new_c] = {r, c}; 
                q.push({new_r, new_c});
            }
        }
    }

    int max_dist = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                if(dist[i][j] == -1){
                    // max_dist = dist[i][j];
                    cout << -1 << endl;
                    return 0
                }
                max_dist = max(max_dist, dist[i][j]);
            }
        }
    }

    cout << max_dist << endl;

    
}