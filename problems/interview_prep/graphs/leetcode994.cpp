#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    void rot(vector<vector<int>>& grid, vector<pair<int, int>> r_oranges_idx) {
        int m = grid.size();
        int n = grid[0].size();
        if (r_oranges_idx.empty()) return;

        for (auto r_orange : r_oranges_idx) {
            
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int counter = 0;        
        unordered_set<int> visited;

        

    }
};