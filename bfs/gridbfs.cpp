#include<bits/stdc++.h>
#include<bit> // for bit operations always use unsigned integers
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;

map<int, int> dist; // to store distance of each node from the start node 
map<int, int> parent; // to store the parent of each node in the bfs tree, used for path reconstruction

int main(){

    int n, m; cin >> n >> m;
    // n = rows, m = columns

    /** all the ways to declare grid: 
     * vector<vector<int>> grid(n, vector<int>(m)); // 2D vector
     * int grid[n][m]; // 2D array
     * vector<int> grid[n]; // array of vectors
     * vector<vector<int>> grid; // 2D vector without initialization
     * vector<vector<int>> grid(n); // 2D vector with only rows initialized
     * vector<vector<int>> grid(m, vector<int>(n)); // 2D vector with rows and columns swapped
     * vector<vector<int>> grid(n, vector<int>(m, 0)); // 2D vector with rows and columns initialized with 0
     * vector<vector<int>> grid(n, vector<int>(m, -1)); // 2D vector with rows and columns initialized with -1
     * vector<vector<int>> grid(n, vector<int>(m, 1)); // 2D vector with rows and columns initialized with 1
     * vector<vector<int>> grid(n, vector<int>(m, 2)); // 2D vector with rows and columns initialized with 2
     * vector<vector<int>> grid(n, vector<int>(m, 3)); // 2D vector with rows and columns initialized with 3
     * vector<string> grid;
       vector<vector<bool>> visited;
       vector<vector<int>> dist;
       vector<vector<pair<int,int>>> parent;
     */

    vector<vector<int>> grid(n, vector<int>(m)); // 2D vector to store the grid

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false)); // 2D vector to store the visited status of each cell
    vector<vector<int>> dist(n, vector<int>(m, -1)); // 2D vector to store the distance of each cell from the start cell

    pair<int, int> start, target;
    cin >> start.first >> start.second;
    cin >> target.first >> target.second;


    if(grid[start.first][start.second] == 1){
        cout << "Start cell is blocked." << endl;
        return 0;
    }
    if(grid[target.first][target.second] == 1){
        cout << "Target cell is blocked." << endl;
        return 0;
    }


    // for parent
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1})); // 2D vector to store the parent of each cell in the bfs tree, initialized with (-1, -1) to indicate no parent   


    // queue for bfs
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0; // distance of the start cell from itself is 0

    int dr[4] = {-1, 1, 0, 0}; // for up, down
    int dc[4] = {0, 0, -1, 1}; // for left, right
    
    while(!q.empty()){
        pair<int,int> cell = q.front();
        cout << "Visiting cell: (" << cell.first << ", " << cell.second << ")" << endl;
        q.pop();

        int r = cell.first;
        int c = cell.second;

        for(int i = 0; i < 4; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            bool boundarycondition = (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m); // check if the new cell is within the grid boundaries
            
            if(boundarycondition && !visited[new_r][new_c] && grid[new_r][new_c] == 0){ // check if the new cell is not visited and not blocked
                
                visited[new_r][new_c] = true; // mark the new cell as visited
                dist[new_r][new_c] = dist[r][c] + 1; // update the distance of the new cell from the start cell
                
                parent[new_r][new_c] = {r, c}; // update the parent of the new cell
                
                q.push({new_r, new_c}); // push the new cell to the queue for further exploration
            }
        }
    }


    

    if(dist[target.first][target.second] != -1){
        cout << "Shortest distance from start to target: " << dist[target.first][target.second] << endl;
    } else {
        cout << "Target is not reachable from start." << endl;
    }

    if(dist[target.first][target.second] != -1){
        vector<pair<int, int>> path; // to store the path from start to target
        pair<int, int> current = target;

        while(current.first != start.first || current.second != start.second){ // until we reach the start cell
            path.push_back(current);
            current = parent[current.first][current.second]; // move to the parent cell
        }
        path.push_back(start); // add the start cell to the path

        reverse(path.begin(), path.end()); // reverse the path to get it from start to target

        cout << "Path from start to target: ";
        for(auto cell : path){
            cout << "(" << cell.first << ", " << cell.second << ") -> ";
        }
        cout <<"end " << endl;
    }

    
}