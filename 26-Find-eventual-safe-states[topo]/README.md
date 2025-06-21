# Find Eventual Safe States[by topo sort]🫨

## [Problem link](https://www.geeksforgeeks.org/problems/eventual-safe-states/1)🧟
# Code👻

```c++
// User function Template for C++
// by bfs topo sort
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>adjRev[V];
        
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            //i->it
            //it->i
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)q.push(i);
        }
        vector<int>safeNodes;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            safeNodes.push_back(curr);
            for(auto ngbr:adjRev[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0)q.push(ngbr);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};

```