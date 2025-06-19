# Number-of-enclaves📩

# 👉🏻[Problem Link](https://leetcode.com/problems/number-of-enclaves/)

# Code[BFS]

```c++
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int ,int>>q;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        //traverse the boundary cells

        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && grid[0][j] == 1){
                q.push({0,j});
                vis[0][j] = 1;
            }
            //last row
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                q.push({n-1,j});
                vis[n-1][j] =  1;
            }
        }

        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            //last col
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        //start bfs from the boundary 1's
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        // now check which 1 are visited because of the boundary 1's
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;

                }
            }
        }
        return count;
    }
};

//tc : O(n x m x 4)
//sc : O(n x m)
```


