# Number of Distinct Islands🏝️🕌

# [problem link](https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1)

# Code[DFS]😍

```c++
// User function Template for C++

class Solution {
  private: 
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int row0,int col0,int drow[],int dcol[],vector<pair<int,int>>&v){
      int n = grid.size();
      int m = grid[0].size();
      vis[row][col] = 1;
      v.push_back({row-row0,col-col0});
      for(int i=0;i<4;i++){
          int nrow = row + drow[i];
          int ncol = col + dcol[i];
          
          if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
              dfs(nrow,ncol,grid,vis,row0,col0,drow,dcol,v);
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,vis,i,j,drow,dcol,v);
                    s.insert(v);
                    
                }
            }
        }
        return s.size();
        
    }
};

```
# Code[BFS]
```c++

```
# Read this 😉
🧠 Total Time Complexity:
cpp
Copy
Edit
O(n × m) for DFS + O(K × L log K) for set insertion
Where:

K is the number of distinct islands,

L is the average number of cells per island.

👉 In worst-case approximation, total time complexity = O(n × m × log(n × m))

✅ Space Complexity
1. Visited Matrix
vector<vector<int>> vis(n, vector<int>(m, 0));
Space = O(n × m) for visited matrix.

2. Recursive Stack (DFS)
In the worst case, DFS goes as deep as the number of land cells = O(n × m) (if the whole grid is one big island).

So, worst-case recursive stack = O(n × m)

3. Set of Unique Islands

set<vector<pair<int,int>>> s;
Suppose there are K distinct islands.

Each island takes O(L) space (L = island size).

Total = O(K × L) = worst case O(n × m).

🧠 Total Space Complexity:

O(n × m) + O(n × m) + O(n × m) = O(n × m)
✅ Final Summary
Metric	Complexity
Time Complexity	O(n × m × log(n × m))
Space Complexity	O(n × m)

This is optimal for grid-based island problems using DFS + hashing of island shape
