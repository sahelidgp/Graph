# 👩🏻‍💻Find-eventual-safe-nodes

## 👉🏻[Problem link](https://leetcode.com/problems/find-eventual-safe-states/description/)

### Any node who is part of a cycle or leads to a cycle is a safe nodes

# Code
```c++
class Solution {
private:
    bool dfsCheck(int node,vector<int>& vis,vector<int>& pathvis,vector<int> &safeNodes,vector<vector<int>>& graph){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfsCheck(it,vis,pathvis,safeNodes,graph) == true){
                    return true;
                }
            }else if(pathvis[it])return true;
            
        }
        pathvis[node] = 0;
        safeNodes.push_back(node);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        vector<int>check(v,0);

        vector<int>safeNodes;
        for(int i=0;i<v;i++){
            if(!vis[i])dfsCheck(i,vis,pathvis,safeNodes,graph);
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
```
# Using extra check array

```c++
class Solution {
private:
    bool dfsCheck(int node,vector<int>& vis,vector<int>& pathvis,vector<int> &check,vector<vector<int>>& graph){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfsCheck(it,vis,pathvis,check,graph) == true){
                    return true;
                }
            }else if(pathvis[it])return true;
            
        }
        pathvis[node] = 0;
        check[node] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        vector<int>check(v,0);

        vector<int>safeNodes;
        for(int i=0;i<v;i++){
            if(!vis[i])dfsCheck(i,vis,pathvis,check,graph);
        }
        for(int i=0;i<v;i++){
            if(check[i] == 1)safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
```

