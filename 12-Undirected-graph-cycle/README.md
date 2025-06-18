# Undirected Graph Cycle⭕

# 👉🏻[Problem link](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

### DFS Code

```c++
class Solution {
  private:
    bool detect(int src,int parent,vector<vector<int>>&adj,vector<int>&vis){
        vis[src] = 1;
        
        for(auto adjnode: adj[src]){
            if(!vis[adjnode]){
               if(detect(adjnode,src,adj,vis)) return true;
            }else {
                if(adjnode != parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        //make the adjacency list
        int n = edges.size();
       vector<vector<int>> adj(V);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }

        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,-1,adj,vis))
                return true;
                
            }
        }
        return false;
    }
};
```


### BFS COde

```c++
class Solution {
  private:
    bool detect(int src,vector<vector<int>>&adj,vector<int>&vis){
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            for(auto it : adj[node]){
                if(it != parent && !vis[it]){
                    q.push({it,node});
                    vis[it] = 1;
                }else if(it != parent && vis[it])return true;
            }
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        //make the adjacency list
        int n = edges.size();
       vector<vector<int>> adj(V);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }

        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis))
                return true;
                
            }
        }
        return false;
    }
};
```

`READ THIS`

✅ Time Complexity: O(V + E)
V = number of vertices

E = number of edges

Why:

You iterate through all vertices once (for (int i = 0; i < V; i++)).

For each vertex, you visit its adjacent nodes using BFS (each edge is checked at most twice — once from each endpoint).

So, total time is linear in the number of vertices and edges.

✅ Space Complexity: O(V + E)
Why:

adj: Adjacency list stores E total entries (since undirected, each edge is stored twice) → O(E)

vis: Visited array of size V → O(V)

queue: In the worst case, it can hold up to O(V) elements.

So overall space used is O(V + E).

Summary:
Time: O(V + E)

Space: O(V + E)

Efficient for sparse graphs.