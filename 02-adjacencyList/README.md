# 👩🏻‍💻Print adjacency list
 [problem link](https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1)

Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

Example 1:
```
Input:
V = 5, E = 7
edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]

Output: 
[[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
```
![Description](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701247/Web/Other/blobid2_1744376584.jpg)

Explanation:
```
Node 0 is connected to 1 and 4.
Node 1 is connected to 0,2,3 and 4.
Node 2 is connected to 1 and 3.
Node 3 is connected to 1,2 and 4.
Node 4 is connected to 0,1 and 3.
```
Example 2:
```
Input:
V = 4, E = 3
edges = [[0,3], [0,2], [2,1]]
  
Output: 
[[2,3], [2], [0,1], [0]]
```
![imag](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701247/Web/Other/blobid5_1744376643.jpg)
Explanation:
```
Node 0 is connected to 2 and 3.
Node 1 is only connected to 2.
Node 2 is connected to 0 and 1.
Node 3 is only connected to 0.
```
Constraints:
```
1 ≤ V, E ≤ 105
```

# 💡 So when to use which?
Use auto& it if you don't want to copy and maybe want to change the values.

Use auto it if you want a safe copy and don’t want to change anything accidentally.

## code
```c++
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto it : edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        return adj;
    }
};
```
