# 👩🏻‍💻Distance of nearest cell having 1

# [problem link](https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1)◀️

# Code 

```c++
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));

        int t = 0;
        //O(n x m)
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};
        //O(n x m x 4)
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = t+1;
                 }
            }
            
        }
        return ans;
    }
};
```
# Code Iterative 
```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> d(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        //for(int i=0;i<d.size();i++) d[i]=new vector<int>(mat[i].size(),INT_MAX);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    d[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            if(x>0&&d[x-1][y]>d[x][y]+1){
                d[x-1][y]=d[x][y]+1;
                q.push({x-1,y});
            }
            if(x<d.size()-1&&d[x+1][y]>d[x][y]+1){
                d[x+1][y]=d[x][y]+1;
                q.push({x+1,y});
            }
            if(y>0&&d[x][y-1]>d[x][y]+1){
                d[x][y-1]=d[x][y]+1;
                q.push({x,y-1});
            }
            if(y<d[x].size()-1&&d[x][y+1]>d[x][y]+1){
                d[x][y+1]=d[x][y]+1;
                q.push({x,y+1});
            }
        }return d;
    }
};
```
sc = > O(n*m)
tc => O(n*m*4)

