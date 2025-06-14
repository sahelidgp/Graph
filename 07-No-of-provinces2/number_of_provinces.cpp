// class Solution {
// private:
//     void bfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
//         queue<int>q;
//         q.push(node);
//         vis[node]=1;
//         while(!q.empty()){
//             int curr = q.front();
//             q.pop();
//             for(int j=0;j<isConnected[curr].size();j++){
//                 if(isConnected[curr][j] == 1){
//                     if(!vis[j]){
//                         q.push(j);
//                         vis[j] = 1;
//                     }
//                 }
//             }
//         }
//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         int count = 0;
//         //visited vector
//         vector<int>vis(n,0);
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//             bfs(i,isConnected,vis);
//             count++;
//             }
//         }
//         return count;
//     }
// };