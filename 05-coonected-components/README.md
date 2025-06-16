# 👩🏻‍💻Connected Components in an Undirected Graph
[problem link](https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1)

Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :
```
Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
```
Explanation:
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/893290/Web/Other/blobid1_1744798106.jpg)
```
Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
Output: [[0, 1, 6], [2, 3, 4], [5]]
```
Explanation:
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/893290/Web/Other/blobid0_1744797809.jpg)
Constraints:
```
1 ≤ V ≤ 105
1 ≤ edges.size() ≤ 105
0 <= edges[i][0], edges[i][1] < V
```
#  DFS approach😉
```c++

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
```

sc : O(n)[traversing n nodes ] + O(n) [visited] + O(n)[recursion stack space]

tc : O(n) + O(2E)

# Code BFS 😍
```c++


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
```
