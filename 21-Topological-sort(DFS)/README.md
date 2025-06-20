# Topological Sort🫠🤌🏻

# [problem link](https://www.geeksforgeeks.org/problems/topological-sort/1)🧟
### Using dfs
```c++
class Solution {
  private:
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it,vis,st,adj);
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>vis(V,0);
        stack<int>st;
        vector<vector<int>>adj(V);
        
        int e = edges.size();
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
```