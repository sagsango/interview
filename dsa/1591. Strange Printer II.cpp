/*
1591. Strange Printer II
Solved
Hard

Topics

Companies

Hint
There is a strange printer with the following two special requirements:

On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
Once the printer has used a color for the above operation, the same color cannot be used again.
You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.

Return true if it is possible to print the matrix targetGrid, otherwise, return false.

 

Example 1:


Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
Output: true
Example 2:


Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
Output: true
Example 3:

Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
Output: false
Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
 

Constraints:

m == targetGrid.length
n == targetGrid[i].length
1 <= m, n <= 60
1 <= targetGrid[row][col] <= 60
  */

class Solution {
public:
    bool isPrintable(vector<vector<int>>& mat) {

        /*

            1, 1, 1, 1
            1, 1, 3, 3
            1, 1, 3, 4
            5, 5, 1, 4



            1, 1, 1, 1, 
            1, 2, 2, 1,
            1, 2, 2, 1,
            1, 1, 1, 1, 



            1, 2, 1
            2, 1, 2
            1, 2, 1


        */

        vector<int> g[61];
        vector<int> xmax(61, -1e9), xmin(61, +1e9), ymax(61, -1e9), ymin(61, +1e9);
        int n = mat.size();
        int m = mat[0].size();

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                xmax[mat[i][j]] = max(xmax[mat[i][j]], i);
                xmin[mat[i][j]] = min(xmin[mat[i][j]], i);
                ymax[mat[i][j]] = max(ymax[mat[i][j]], j);
                ymin[mat[i][j]] = min(ymin[mat[i][j]], j);
            }
        }

        for (int u=1; u<61; ++u) {
            for (int i=xmin[u]; i<=xmax[u]; ++i) {
                for (int j=ymin[u]; j<=ymax[u]; ++j) {
                    if (mat[i][j] != u) {
                        g[u].push_back(mat[i][j]);
                    }
                }
            }

        }


        vector <int> clr(61);
        int cycle = 0;


        function<void(int)>dfs = [&](int u) {
            clr[u] = 1;
            for (auto v:g[u]) {
                if (!clr[v]) {
                    dfs(v);
                } else if(clr[v] == 1) {
                    cycle = 1;
                }
            }
            clr[u] = 2;
        };


        for (int i=1; i<61; ++i) {
            if (!clr[i]) {
                dfs(i);
            }
        }

        return !cycle;

        
    }
};
