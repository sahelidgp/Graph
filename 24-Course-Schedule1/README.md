# Course Schedule1📖

## 🦋[problem link](https://leetcode.com/problems/course-schedule/description/)

# Code👻
```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //make the adjacency list
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        int e = prerequisites.size();
        for(int i=0;i<e;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            cnt++;
            q.pop();
            for(auto ngbr : adj[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0)q.push(ngbr);
            }
        }
        if(cnt == numCourses)return true;
        return false;
    }
};
```