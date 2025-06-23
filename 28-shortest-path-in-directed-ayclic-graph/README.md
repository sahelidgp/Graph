# 😉shortest-path-in-directed-ayclic-graph
# [Problem link](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1)🧟

# Code🫠

```c++
class Solution {
  private:
    void topoSort(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]){
            int ngbr = it.first;
            if(!vis[ngbr]){
                topoSort(ngbr, adj, vis, st);
            }
        }
        st.push(node); 
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v, d});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        
            
        //O(V+E)
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        //O(V+E)
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(dist[node] != 1e9) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int d = it.second;
                    if(dist[node] + d < dist[v]) {
                        dist[v] = dist[node] + d;
                    }
                }
            }
        }

        // Convert unreachable distances to -1
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};

```