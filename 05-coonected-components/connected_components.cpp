//by dfs approach
class Solution {
  public:
    void dfs(int node,vector<int>&temp,vector<int>&vis,vector<vector<int>>& adj){
        // mark the current node as visited
        vis[node] = 1;
        temp.push_back(node);
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                dfs(ngbr,temp,vis,adj);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        //make the adjacency list
        vector<vector<int>>adj(V);
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<vector<int>>res;
        vector<int>vis(V,0);
         vector<int>temp;
        for(int i=0;i<V;i++){
        
            if(!vis[i]){
               
                dfs(i,temp,vis,adj);
                res.push_back(temp);
                temp.clear();
            }
            
        }
        return res;
        
    }
};

//by bfs approach

class Solution {
  public:
    void bfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&temp){
        // mark the current node as visited
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            vis[curr] = 1;
            q.pop();
            temp.push_back(curr);
        for(auto ngbr : adj[curr]){
            if(!vis[ngbr]){
                q.push(ngbr);
                vis[ngbr] = 1;
            }
          }
        }
     
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        //make the adjacency list
        vector<vector<int>>adj(V);
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<vector<int>>res;
        vector<int>vis(V,0);
         
        for(int i=0;i<V;i++){
        
            if(!vis[i]){
               vector<int>temp;
                bfs(i,vis,adj,temp);
                res.push_back(temp);
            }
            
        }
        return res;
        
    }
};
//sc : O(n)[traversing n nodes ] + O(n) [visited] + O(n)[recursion stack space]
//tc : O(n) + O(2E)