# Undirected Graph Cycle⭕

# [problem link](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)◀️

### Code [BFS]😉

```c++
class Solution {
  private:
    bool detect(int src,vector<vector<int>>&adj,vector<int>&vis){
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            for(auto it : adj[node]){
                if(it != parent && !vis[it]){
                    q.push({it,node});
                    vis[it] = 1;
                }else if(it != parent && vis[it])return true;
            }
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        //make the adjacency list
        int n = edges.size();
       vector<vector<int>> adj(V);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }

        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis))
                return true;
                
            }
        }
        return false;
    }
};
```
### TC : O(N+2E)+O(N)  < second O(N) for components >   O(N+2E because we are total N nodes and each nodes is traversing for its neighbours to total 2E = summation of all the degrees  each nodes are not traversing 2E times that's why it is not O(N*2E) 
### SC: O(N) + O(N) queue + vis


### Code [DFS]😉

```c++

```
