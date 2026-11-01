#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void dfs(vector<vector<char>> &grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        // visit all neighbord
        dfs(grid, r + 1, c);    // below
        dfs(grid, r - 1, c);    // above
        dfs(grid, r, c + 1);    // right
        dfs(grid, r, c - 1);    // left

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int num_islands = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    num_islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;


    }
};
