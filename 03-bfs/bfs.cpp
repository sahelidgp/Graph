//    #include<bits/stdc++.h>
//    #include<vector>
//    using namespace std;
//    #include<queue>
//    // Function to return Breadth First Traversal of given graph.
//     vector<int> bfs(vector<vector<int>> &adj) {
//         // Code here
//         int n = adj.size();
//         int vis[n] = {0};
//         vis[0] = 1;
//         queue<int>q;
//         q.push(0);
//         vector<int> bfs;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             bfs.push_back(node);
            
//             for(auto &adjnode : adj[node]){
//                 if(!vis[adjnode]){
//                     q.push(adjnode);
//                     vis[adjnode] = 1;
//                 }
//             }
//         }
//         return bfs;
//     }

// //sc : O(3n)
// //tc: O(n) + O(2E)