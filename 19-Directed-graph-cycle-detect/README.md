# 👩🏻‍💻Cycle detect in Directed Graph

# [Problem Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)◀️
# Approach:
We will be doing dfs and if we find any node which is priviously visited in the same path then cycle exist
# DFS Code😉

```c++
class Solution {
  private:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        //neighbours
        for(auto ngbr : adj[node]){
            //if not visited
            if(!vis[ngbr]){
                if(dfs(ngbr,adj,vis,pathvis) == true)
                    return true;
                }
        // if visited in the same path
              else if(vis[ngbr]){
                    if(pathvis[ngbr]) return true;
                }
        }
        pathvis[node] = 0;
        return false;
        
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        int e = edges.size();
        vector<vector<int>>adj(V);
        
        // make the adjacency list;
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        // adj list
        
        /*
            0 : {1,2}
            1:  {2}
            2: {0,3}
            3 : {}
        
        */
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis) == true)return true;
            }
        }
        return false;
        
    }
};

//tc : O(V+E)  as directed graph total neighbours = no of edges
// sc : O(2N)  vis + pathvis
```

# We can do this using single visited array using different notations
not visited >  0
visited > 1
pathvisited > 2

```c++
class Solution {
  private:
    // DFS function to detect cycle in a directed graph
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        // Mark the current node as being visited (state 1)
        vis[node] = 1;

        // Traverse all the neighbors of the current node
        for (auto ngbr : adj[node]) {
            // If the neighbor has not been visited yet
            if (vis[ngbr] == 0) {
                // Recur for the neighbor
                if (dfs(ngbr, adj, vis) == true)
                    return true;  // Cycle detected in the subtree
            }
            // If the neighbor is already in the current DFS path
            else if (vis[ngbr] == 1) {
                // Back edge found → cycle exists
                return true;
            }
        }

        // After processing all neighbors, mark the node as fully visited (state 2)
        vis[node] = 2;
        return false;  // No cycle found starting from this node
    }

  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Number of vertices is V
        // edges is a list of pairs [u, v] where there is a directed edge u → v

        // Create the adjacency list representation of the graph
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);  // Directed edge from u to v
        }

        // Visited array with 3 states:
        // 0 → unvisited
        // 1 → visiting (in the current recursion stack)
        // 2 → visited (completely processed)
        vector<int> vis(V, 0);

        // Run DFS from all unvisited nodes (to handle disconnected graphs)
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis) == true)
                    return true;  // Cycle detected
            }
        }

        return false;  // No cycle detected in any component
    }
};

```

