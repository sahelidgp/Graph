# Detect cycle in directed graph by topo😎

## [problem link](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)↩️

# Code🧟

```c++
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
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
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            //node is in your topo sort so please remove it from the indegree
            for(auto ngbr:adj[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0)q.push(ngbr);
            }
        }
        if(cnt == V)return false;  // cycle does not exist as topo sort possible
        else return true; //cycle exists
    }
};
```