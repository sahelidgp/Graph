# Kahn's Algorithm🫠
### BFS
### 👉🏻[Problem link](https://www.geeksforgeeks.org/problems/topological-sort/1)

# Code😉
```c++
//Kahn's algorithm
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<int>indegree(V,0);

    //make the adjacency list
    vector<vector<int>>adj(V);
    int e = edges.size();
       for(int i=0;i<e;i++){
           int first = edges[i][0];
           int sec = edges[i][1];
           indegree[sec]++;
           adj[first].push_back(sec);
       }
       
       queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            //node is in your topo sort so please remove it from the indegree
            for(auto ngbr:adj[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0)q.push(ngbr);
            }
        }
        return topo;
    }
};
//sc : O(V) + O(V) for queue and indegree
// tc: O(V+E)

```