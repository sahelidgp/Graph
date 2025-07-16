# 👩🏻‍💻Number of Provinces

[problem link](https://www.geeksforgeeks.org/problems/number-of-provinces/1)

Difficulty: Medium


Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/706298/Web/Other/blobid0_1744377052.jpg)
```
Input:[[1, 0, 1],[0, 1, 0],[1, 0, 1]]
 
Output:
2
```
Explanation:
```
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
```
Example 2:
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/893290/Web/Other/blobid0_1744797809.jpg)
```
Input:[[1, 1],[1, 1]]
Output :
1
```
Your Task:
```  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj(as a 2d vector) as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.
```
```

Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)
```
```

Constraints:
1 ≤ V ≤ 500
```
# code (DFS)
```c++
// User function Template for C++

class Solution {
  public:
  
    void dfs(int node,vector<vector<int>> &adj,vector<int>&vis){
        vis[node] = 1;
        for(int j=0;j<adj[node].size();j++){
             if(adj[node][j] == 1){
                 if(!vis[j]){
                  dfs(j,adj,vis);
            }
             }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //visited vector
        int count = 0;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
            dfs(i,adj,vis);
            count++;
            }
        }
    
        return count;
    }
};
```
