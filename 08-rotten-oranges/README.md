# Rotting Oranges🍊

# 👉🏻[Porblem link](https://leetcode.com/problems/rotting-oranges/description/)

# code [Using bfs] 
### MY approach😍
```c++
class Solution {
private:
    void bfs(int row,int col , vector<vector<int>>& grid,vector<vector<int>>& ans,int m,int n,int &count,queue<pair<pair<int,int>,int>>&q){
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            count = t; 
            q.pop();
             int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
           
            for(int i = 0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                 
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol] == 1  && ans[nrow][ncol] != 2 ){
                    q.push({{nrow,ncol},t+1});
                    ans[nrow][ncol] = 2;
                }
            }
    
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j] == 1){
                    count = -1;
                    break;
                }
            }
        }

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //search the rotten orange
        queue<pair<pair<int,int>,int>>q;
        int sr = -1,sc = -1;
        int time = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    sr = i;
                    sc = j;
                    q.push({{sr,sc},time});
                }
            }
        }
        int count = 0;
        vector<vector<int>>ans = grid; //copy the original array to ans
        bfs(sr,sc,grid,ans,m,n,count,q);
        return count;
    }
};
```
# other approach😉

```c++
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q; // {{row, col}, time}
        int countfresh = 0;
        int vis[m][n];

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2; // Mark as rotten
                } else {
                    vis[i][j] = 0; // Not visited
                    if(grid[i][j] == 1) countfresh++;
                }
            }
        }

        int tm = 0;
        int count = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                   vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }

        if(count != countfresh) return -1;
        return tm;
    }
};

```