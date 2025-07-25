# 👩🏻‍💻DFS of Graph
 [problem link](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

Examples:

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700203/Web/Other/blobid0_1728647807.jpg)
```
Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 4, 3, 1]
```
Explanation: 
```
Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
```
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700203/Web/Other/blobid1_1728648013.jpg)

Input:
```
 adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

Output: [0, 1, 2, 3, 4]
```
Explanation:
```
 Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4
```
Constraints:
```
1 ≤ V = adj.size() ≤ 104
1 ≤ adj[i][j] ≤ 104
```
# code using recursion
```c++
class Solution {
public:
    void dfsUtil(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls) {
        vis[node] = 1;
        ls.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsUtil(it, adj, vis, ls);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ls;

        int start = 0;
        dfsUtil(start, adj, vis, ls);

        return ls;
    }
};
//sc : O(n)[traversing n nodes ] + O(n) [visited] + O(n)[recursion stack space]
//tc : O(n) + O(2E)
```
# code using stack
```c++
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> v(adj.size(),0);
        stack<int> s;
        vector<int> dfs;
        s.push(0);
        int val;
        while(!s.empty()){
            val=s.top();
            s.pop();
            if(v[val]==0){
                v[val]=1;
                dfs.push_back(val);
                for(int i=adj[val].size()-1;i>=0;i--){
                    if(v[adj[val][i]]==0){
                        s.push(adj[val][i]);
                    }
                } 
        }
            
        }
        return dfs;
    }
};
```
