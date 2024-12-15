/*
1548. The Most Similar Path in a Graph
Solved
Hard



We have n cities and m bi-directional roads where roads[i] = [ai, bi] connects city ai with city bi. Each city has a name consisting of exactly three upper-case English letters given in the string array names. Starting at any city x, you can reach any city y where y != x (i.e., the cities and the roads are forming an undirected connected graph).

You will be given a string array targetPath. You should find a path in the graph of the same length and with the minimum edit distance to targetPath.

You need to return the order of the nodes in the path with the minimum edit distance. The path should be of the same length of targetPath and should be valid (i.e., there should be a direct road between ans[i] and ans[i + 1]). If there are multiple answers return any one of them.

The edit distance is defined as follows:


 

Example 1:
Input: n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]], names = ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
Output: [0,2,4,2]
Explanation: [0,2,4,2], [0,3,0,2] and [0,3,1,2] are accepted answers.
[0,2,4,2] is equivalent to ["ATL","LAX","HND","LAX"] which has edit distance = 1 with targetPath.
[0,3,0,2] is equivalent to ["ATL","DXB","ATL","LAX"] which has edit distance = 1 with targetPath.
[0,3,1,2] is equivalent to ["ATL","DXB","PEK","LAX"] which has edit distance = 1 with targetPath.

Example 2:
Input: n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]], names = ["ATL","PEK","LAX","DXB"], targetPath = ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
Output: [0,1,0,1,0,1,0,1]
Explanation: Any path in this graph has edit distance = 8 with targetPath.


Example 3:
Input: n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]], names = ["ATL","PEK","LAX","ATL","DXB","HND"], targetPath = ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
Output: [3,4,5,4,3,2,1]
Explanation: [3,4,5,4,3,2,1] is the only path with edit distance = 0 with targetPath.
It's equivalent to ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]


*/


class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {

        vector<vector<int>> g(n);
        for (auto &edg: roads) {
            int u = edg[0];
            int v = edg[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int m = targetPath.size();

        int eDis[n][m]; // eDis[cur_graph_node][tagetPath node at index j] = cost
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                eDis[i][j] = 0;
                for (int k=0; k<3; ++k) {
                    eDis[i][j] |= (names[i][k] != targetPath[j][k]);
                }
            }
        }

        int dp[n][m], pr[n][m]; // dp[cur_graph_node][targetPath index covered till now] = min_edit_distance
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                dp[i][j] = 1e9;
                pr[i][j] = -1;
            }
            dp[i][0] = eDis[i][0];
        }

        for (int j=0; j+1<m; ++j) {
            for (int i=0; i<n; ++i) {
                for (auto v:g[i]) {
                    if (dp[v][j+1] >  dp[i][j] + eDis[v][j+1]) {
                        dp[v][j+1] =  dp[i][j] + eDis[v][j+1];
                        pr[v][j+1] =  i;
                    }
                }
            }
        }
        
        int ans = 1e9, node;
        for (int i=0; i<n; ++i) {
            if (ans > dp[i][m-1]) {
                ans = dp[i][m-1];
                node = i;
            }
        }

        /*for (int i=0; i<n; ++i) {
            cout << i <<":";
            for (int j=0; j<m; ++j) {
                cout << dp[i][j] <<",";
            }
            cout << endl;

        }*/
        
        vector <int> path;
        for (int i=m-1; i>=0; --i) {
            path.push_back(node);
            node = pr[node][i];
        }

        reverse(path.begin(), path.end());

        return path;
    }
};
