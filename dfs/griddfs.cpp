#include<bits/stdc++.h>
#include<bit> // for bit operations always use unsigned integers
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    function<void(int,int)> dfs = [&](int r, int c){
        visited[r][c] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++){
            
            int nr = r + dr[i];
            int nc = c + dc[i];

            bool boundarycondition = (nr >= 0 && nr < n && nc >= 0 && nc < m);
            if(boundarycondition && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc);
            }
        }
    };

    int island_count = 0;
    for(int i= 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                island_count++;
                dfs(i, j);
            }
        }
    }


    cout << "Number of islands: " << island_count << endl;
    

}