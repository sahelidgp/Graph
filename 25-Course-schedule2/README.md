# Course Schedule2📖

## [Problem link](https://leetcode.com/problems/course-schedule-ii/)🧟

# Code🤓

```c++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int e = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        
        for(int i=0;i<e;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for(auto ngbr:adj[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0)q.push(ngbr);
            }
        }
        if(topo.size() == numCourses)
        return topo;
        return {};
    }
};
```