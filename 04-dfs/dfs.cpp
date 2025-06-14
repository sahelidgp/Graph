// class Solution {
// public:
//     void dfsUtil(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls) {
//         vis[node] = 1;
//         ls.push_back(node);

//         for (auto it : adj[node]) {
//             if (!vis[it]) {
//                 dfsUtil(it, adj, vis, ls);
//             }
//         }
//     }

//     vector<int> dfs(vector<vector<int>>& adj) {
//         int n = adj.size();
//         vector<int> vis(n, 0);
//         vector<int> ls;

//         int start = 0;
//         dfsUtil(start, adj, vis, ls);

//         return ls;
//     }
// };
// //sc : O(n)[traversing n nodes ] + O(n) [visited] + O(n)[recursion stack space]
// //tc : O(n) + O(2E)
