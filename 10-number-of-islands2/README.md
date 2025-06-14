# Number of Islands[Leetcode]🏝️

# [problem link](https://leetcode.com/problems/number-of-islands/)◀️
 
 ## BFS Code😊
```c++
class Solution {
private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            //neighbour
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++)
                {
                    int nRow = r + delRow[i];
                    int nCol = c + delCol[i];

                    if(nRow>=0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                        q.push({nRow,nCol});
                        vis[nRow][nCol] = 1;
                    }
                }
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //visited vector 
        vector<vector<int>>vis(n,vector<int>(m,0));
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    island++;
                    bfs(i,j,vis,grid);
                    
                }
            }
        }
        return island;
    }
};
```

 
 ## DFS Code😉
```c++
class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
            //neighbour
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++)
                {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(nRow>=0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                     dfs(nRow,nCol,vis,grid);
                    }
                }
            
        }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //visited vector 
        vector<vector<int>>vis(n,vector<int>(m,0));
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    island++;
                    dfs(i,j,vis,grid);
                    
                }
            }
        }
        return island;
    }
};
```
