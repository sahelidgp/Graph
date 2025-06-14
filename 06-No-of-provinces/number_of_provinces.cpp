// // User function Template for C++

// class Solution {
//   public:
  
//     void dfs(int node,vector<vector<int>> &adj,vector<int>&vis){
//         vis[node] = 1;
//         for(int j: adj[node]){
//             if(adj[node][j]){
//              if(!vis[j]){
//                 dfs(j,adj,vis);
//              } 
//             }
//         }
//     }
//     int numProvinces(vector<vector<int>> adj, int V) {
//         // code here
//         //visited vector
//         int count = 0;
//         vector<int>vis(V,0);
        
//         for(int i=0;i<V;i++){
//             if(!vis)
//             dfs(i,adj,vis);
//             count++;
            
//         }
    
//         return count;
//     }
// // };