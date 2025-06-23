# Word Ladder 1😉
# [Problem Link](https://leetcode.com/problems/word-ladder/description/)🧟

# Code🦋

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      queue<pair<string,int>>q;
      q.push({beginWord, 1});
      unordered_set<string> st(wordList.begin(),wordList.end());
      st.erase(beginWord);
       
      while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord)return steps;
        for(int i=0;i<word.size();i++){
            char original = word[i];
            //N x word length x26 x log N for ordered set
            for(char ch = 'a';ch <= 'z'; ch++){
                word[i] = ch;
                //if exists in the set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
      }
      return 0;
    }
};

// ✅ Key Points:
// Complexity:
// Time: O(N * L * 26)

// N = number of words in the wordList

// L = length of each word

// Space: O(N) for the queue and set.
```


