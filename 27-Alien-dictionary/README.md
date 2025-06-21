# Alien Dictionary👽

# [Problem Link](https://www.geeksforgeeks.org/problems/alien-dictionary/1)👾

# Code😉

```c++
class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);  // track which characters appear
        
        int s = words.size();
        for (int i = 0; i < s; i++) {
            for (char c : words[i]) {
                present[c - 'a'] = true;
            }
        }

        for (int i = 0; i < s - 1; i++) {
            string first = words[i];
            string sec = words[i + 1];
            int idx = 0;

            while (idx < first.length() && idx < sec.length()) {
                if (first[idx] != sec[idx]) {
                    adj[first[idx] - 'a'].push_back(sec[idx] - 'a');
                    indegree[sec[idx] - 'a']++;
                    break;
                } else {
                    idx++;
                }
            }

            // Invalid case: prefix ordering
            //example: abcd
            //         abc
            if (idx == sec.length() && first.length() > sec.length()) {
                return "";
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) q.push(i);
        }

        string topo = "";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topo.push_back(curr + 'a');
            for (auto ngbr : adj[curr]) {
                indegree[ngbr]--;
                if (indegree[ngbr] == 0) q.push(ngbr);
            }
        }

        // Count present characters only
        int total_chars = count(present.begin(), present.end(), true);
        if (topo.size() == total_chars)
            return topo;
        else
        //if cyclic dependency
            return "";
    }
};

```