
# [problem link ](https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)
# Code
```c++
class Solution {
  public:
  
  void dfsFill(int u,vector<vector<int>>& adj,vector<bool>& visited,stack<int>& st){
      visited[u] = true;
      
      for(int &v : adj[u]){
          if(!visited[v]){
              dfsFill(v,adj,visited,st);
          }
      }
      st.push(u);
  }
  void dfsTraversal(int u,vector<vector<int>>& adjReversed, vector<bool>& visited){
      visited[u] = true;
      
      for(int &v : adjReversed[u]){
          if(!visited[v]){
              dfsTraversal(v, adjReversed,visited);
          }
      }
  }

    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        //STEP1 : store order of dfs in stack
        stack<int> st;
        vector<bool>visited(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsFill(i,adj,visited,st);
            }
        }
        
        //make  a reverse graph
        vector<vector<int>> adjReversed(V);
        for(int u=0;u<V;u++){
            for(int &v : adj[u]){
                //u -> v
                adjReversed[v].push_back(u);
            }
        }
        
        //step3 : call dfs based on stack order
        int countSCC = 0;
        visited = vector<bool>(V,false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                dfsTraversal(node, adjReversed ,visited);
                countSCC++;
            }
        }
        return countSCC;
    }
};
```
# TC: O(V+E)
# SC: O(V+E)