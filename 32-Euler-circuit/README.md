# [Probelm link](https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1)
# Code
```c++
class Solution {
    private:
    void dfs(vector<int>adj[],vector<int>&vis,int node){
        vis[node] = 1;
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(adj,vis,neigh);
            }
        }
    }
  public:
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        vector<int>deg(V,0);
        int evndeg = 0;
        for(int u=0;u<V;u++){
            deg[u] = adj[u].size();
            if(deg[u]%2 == 0)evndeg++;
        }
        
        for(int i=0;i<V;i++){
            if(deg[i])
            {
                dfs(adj,vis,i);
                break;
            }
            
        }
        if(evndeg != V && evndeg != V-2) {
            return 0;
        }
        for(int i=0;i<V;i++){
            if(deg[i] && !vis[i])return 0;
        }
        if(evndeg == V)return 2;
        else return 1;
    }
};

```
# time complexity: O(V+E)
# space complexity: O(V)