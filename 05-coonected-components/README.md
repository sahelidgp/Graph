# 👩🏻‍💻Connected Components in an Undirected Graph
[problem link](https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1)
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :
```
Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
```
Explanation:
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/893290/Web/Other/blobid1_1744798106.jpg)
```
Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
Output: [[0, 1, 6], [2, 3, 4], [5]]
```
Explanation:
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/893290/Web/Other/blobid0_1744797809.jpg)
Constraints:
```
1 ≤ V ≤ 105
1 ≤ edges.size() ≤ 105
0 <= edges[i][0], edges[i][1] < V
```