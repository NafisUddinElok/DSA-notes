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

    cout << "Enter the number of rows and columns in the grid: ";
    int n, m; cin >> n >> m;

    cout << "Enter the grid (0 for open cell, 1 for blocked cell): " << endl;
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
            if(grid[i][j] == 1){
                sources.push_back({i, j});
                visited[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }


    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1})); // 2D vector to store the parent of each cell in the bfs tree, initialized with (-1, -1) to indicate no parent    queue<pair<int, int>> q;
    queue<pair<int, int>> q;

    for(auto source : sources){
        q.push(source);
    }

    int dr[4] = {-1, 1, 0, 0}; // for up, down
    int dc[4] = {0, 0, -1, 1}; // for left, right

    while(!q.empty()){
        pair<int, int> cell = q.front();
        
        q.pop();
        
        int r = cell.first;
        int c = cell.second;

        for(int i = 0; i < 4; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            bool boundarycondition = (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m); // check if the new cell is within the grid boundaries
            
            if(boundarycondition && !visited[new_r][new_c] && grid[new_r][new_c] == 0){ // check if the new cell is not visited and not blocked
                visited[new_r][new_c] = true;
                dist[new_r][new_c] = dist[r][c] + 1; // distance of the new cell is distance of the current cell + 1
                parent[new_r][new_c] = {r, c}; // set the parent of the new cell to the current cell
                q.push({new_r, new_c}); // push the new cell to the queue
            }
        }

    }

    // print the distance of each cell from the nearest source
    cout << "Distance of each cell from the nearest source:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // print the path from each cell to the nearest source
    cout << "Path from each cell to the nearest source:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] != -1){
                vector<pair<int, int>> path; // to store the path from the cell to the nearest source
                pair<int, int> current = {i, j};    
                while(current.first != -1 && current.second != -1){ // until we reach a source cell
                    path.push_back(current);
                    current = parent[current.first][current.second]; // move to the parent cell
                }
                reverse(path.begin(), path.end()); // reverse the path to get the path from the cell to the nearest source
                cout << "Path from cell (" << i << ", " << j << ") to nearest source: ";
                for(auto cell : path){
                    cout << "(" << cell.first << ", " << cell.second << ") -> ";
                }
                cout <<"end " << endl;
            }
            else {
                cout << "No path from cell (" << i << ", " << j << ") to any source." << endl;  
            }
        }
    }

    

    
}