# Numbers of Islands(GFG)🏝️

# [problem link](https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1)◀️

## bfs approach😉
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
            for(int delRow = -1;delRow<=1;delRow++){
                for(int delCol = -1;delCol<=1;delCol++)
                {
                    int nRow = r + delRow;
                    int nCol = c + delCol;

                    if(nRow>=0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == 'L' && !vis[nRow][nCol]){
                        q.push({nRow,nCol});
                        vis[nRow][nCol] = 1;
                    }
                }
            }
        }
    }
public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //visited vector 
        vector<vector<int>>vis(n,vector<int>(m,0));
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'L' && !vis[i][j]){
                    
                    bfs(i,j,vis,grid);
                    island++;
                }
            }
        }
        return island;
    }
};
```
## dfs approach😊
```c++
class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
            vis[row][col] = 1;
            for(int delRow = -1;delRow<=1;delRow++){
                for(int delCol = -1;delCol<=1;delCol++)
                {
                    int nRow = row + delRow;
                    int nCol = col + delCol;

                    if(nRow>=0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == 'L' && !vis[nRow][nCol]){
                        dfs(nRow,nCol,vis,grid);
                        
                    }
                }
            }
            
        
    }
public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //visited vector 
        vector<vector<int>>vis(n,vector<int>(m,0));
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'L' && !vis[i][j]){
                    
                    dfs(i,j,vis,grid);
                    island++;
                }
            }
        }
        return island;
    }
};
```