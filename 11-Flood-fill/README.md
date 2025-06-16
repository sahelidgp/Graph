#  Flood Fill Algorithm🌊 

# [Problem  link](https://leetcode.com/problems/flood-fill/)◀️

## Code

### BFS Approach😉

```c++
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans = image;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int stcolor = image[sr][sc];
        vis[sr][sc] = 1;
        ans[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[] = {0,-1,0,1};
            int delCol[] = {-1,0,1,0};

            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol] == stcolor && !vis[nRow][nCol]){
                    q.push({nRow,nCol});
                    vis[nRow][nCol] = 1;
                    ans[nRow][nCol] = color;
                }
            }
        }
        return ans;

    }
};
```
### DFS Approach😉

```c++
class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int color,int delRow[],int delCol[],int iniColor){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != color){
                dfs(nRow,nCol,ans,image,color,delRow,delCol,iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>>ans = image;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,delRow,delCol,iniColor);
        return ans;
    }
};
```
