#include <vector>
using namespace std;


class Solution {
public:

    // mark the current grid[r][c] (if it exists) 0 and 
    // visit its adjacent entries to mark them zero
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r + 1, c);  // below
        dfs(grid, r - 1, c);  // above
        dfs(grid, r, c + 1);  // right
        dfs(grid, r, c - 1);  // left
    }



    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count_islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count_islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return count_islands;
    }
};