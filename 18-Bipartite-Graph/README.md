# Bipartite Graph👩🏻‍💻

# [Problem link](https://leetcode.com/problems/is-graph-bipartite/submissions/1669494512/)◀️◀

# BFS CODE😉 using extra visited array

```c++
class Solution {
    bool bfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node] = 0;
        vis[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            int col = color[curr];
            q.pop();
            for(auto ngbr : graph[curr]){
                if(!vis[ngbr]){
                    q.push(ngbr);
                    color[ngbr] = !col;
                    vis[ngbr]  = 1;
                }else if(vis[ngbr]){
                    if(color[ngbr] == col)return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
                if(!vis[i]){
                    if(bfs(i,graph,vis,color) == false)return false;
                }
            }
        
        return true;
    }
};
```

# DFS CODE😍

```c++
class Solution {
    bool dfs(int node,int stcolor,vector<vector<int>>& graph,vector<int>&color){
        color[node] = stcolor;
            for(auto ngbr : graph[node]){
                if(color[ngbr] == -1){
                    if(dfs(ngbr,!stcolor,graph,color) == false)return false;
                }else if(color[ngbr] == stcolor)return false;
            }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        int stcolor = 0;
        for(int i=0;i<n;i++){
                    if(color[i] == -1)
                    if(dfs(i,stcolor,graph,color) == false)return false;
                
            }
        return true;
    }
};
```