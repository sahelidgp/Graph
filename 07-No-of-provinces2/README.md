# 👩🏽‍💻547. Number of Provinces

[problem link](https://leetcode.com/problems/number-of-provinces/description/)

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

![](https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg)
```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```
Example 2:

![](https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg)

```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 
```
Constraints:
```
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
```

# code[BFS]
```c++

class Solution {
private:
    void bfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int j=0;j<isConnected[curr].size();j++){
                if(isConnected[curr][j] == 1){
                    if(!vis[j]){
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        //visited vector
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            bfs(i,isConnected,vis);
            count++;
            }
        }
        return count;
    }
};
```