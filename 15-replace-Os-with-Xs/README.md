# Replace-O's-with-X's👩🏻‍💻

# [Problem Link](https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1)◀️◀

# Code[BFS]

```c++
// User function Template for C++

class Solution {
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m =  mat[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'X'));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        for(int j=0;j<m;j++){
           if(mat[0][j] == 'O'){
               q.push({0,j});
               vis[0][j] =  1;
               ans[0][j] = 'O';
               
           }if(mat[n-1][j] == 'O'){
               q.push({n-1,j});
               vis[n-1][j] =  1;
               ans[n-1][j] = 'O';
           }
        }
         for(int i=0;i<n;i++){
           if(mat[i][0] == 'O'){
               q.push({i,0});
               vis[i][0] =  1;
               ans[i][0] = 'O';
               
           }if(mat[i][m-1] == 'O'){
               q.push({i,m-1});
               vis[i][m-1] =  1;
               ans[i][m-1] = 'O';
           }
        }
        
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,-1,0,1};
            
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >0 && nrow<n && ncol>0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = 'O';
                }
            }
            
        }
        
        return ans;
    }
};
```
# Surrounded Region
# [Problem Link](https://leetcode.com/problems/surrounded-regions/description/)
# DFS Code
```c++
class Solution {
private:
void dfs(int r,int c,vector<vector<char>>&board,vector<vector<int>>&vis,int drow[],int dcol[]){
    int n = board.size();
    int m = board[0].size();
    vis[r][c] =  1;
    board[r][c] = 'O';
    for(int i=0;i<4;i++){
        int nrow = r + drow[i];
        int ncol = c + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >=0  && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
            dfs(nrow,ncol,board,vis,drow,dcol);
        }
    }
}
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        //traverse first row and last row
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,board,vis,drow,dcol);
            }
            //last row
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1,j,board,vis,drow,dcol);
            }
        }
        //traverse the first column and last col
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,vis,drow,dcol);
            }
            //last col
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis,drow,dcol);
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j])board[i][j] = 'X';
        }
    }
       
    }
};
//tc: O(nxmx4)
//sc: O(nxm)
```


