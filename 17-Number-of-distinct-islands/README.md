# Number of Distinct Islands🏝️🕌

# [problem link](https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1)

# Code[DFS]

```c++

```

# Read this 😉
🧠 Total Time Complexity:
cpp
Copy
Edit
O(n × m) for DFS + O(K × L log K) for set insertion
Where:

K is the number of distinct islands,

L is the average number of cells per island.

👉 In worst-case approximation, total time complexity = O(n × m × log(n × m))

✅ Space Complexity
1. Visited Matrix
vector<vector<int>> vis(n, vector<int>(m, 0));
Space = O(n × m) for visited matrix.

2. Recursive Stack (DFS)
In the worst case, DFS goes as deep as the number of land cells = O(n × m) (if the whole grid is one big island).

So, worst-case recursive stack = O(n × m)

3. Set of Unique Islands

set<vector<pair<int,int>>> s;
Suppose there are K distinct islands.

Each island takes O(L) space (L = island size).

Total = O(K × L) = worst case O(n × m).

🧠 Total Space Complexity:

O(n × m) + O(n × m) + O(n × m) = O(n × m)
✅ Final Summary
Metric	Complexity
Time Complexity	O(n × m × log(n × m))
Space Complexity	O(n × m)

This is optimal for grid-based island problems using DFS + hashing of island shape
