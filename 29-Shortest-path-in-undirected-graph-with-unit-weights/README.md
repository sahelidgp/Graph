# 29-Shortest-path-in-undirected-graph-with-unit-weights😉

# [Problem Link](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

# Code🧟
```c++
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v = adj.size();
        vector<int>dist(v,1e9);
        
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            for(auto ngbr : adj[node]){
                if(d+1 < dist[ngbr])
                {
                    dist[ngbr] = d+1;
                    q.push({ngbr,d+1});
                }
            }
        }
        
        for(int i=0;i <v;i++){
            if(dist[i] == 1e9)dist[i] = -1;
        }
        return dist;
    }
};
```