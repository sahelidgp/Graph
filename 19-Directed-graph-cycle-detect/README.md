# 👩🏻‍💻Cycle detect in Directed Graph

# [Problem Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)◀️

# DFS Code😉

```c++
class Solution {
  private:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        //neighbours
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                if(dfs(ngbr,adj,vis,pathvis) == true)
                    return true;
                }
              else if(vis[ngbr]){
                    if(pathvis[ngbr]) return true;
                }
        }
        pathvis[node] = 0;
        return false;
        
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        int e = edges.size();
        vector<vector<int>>adj(V);
        
        // make the adjacency list;
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        // adj list
        
        /*
            0 : {1,2}
            1:  {2}
            2: {0,3}
            3 : {}
        
        */
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis) == true)return true;
            }
        }
        return false;
        
    }
};
```

