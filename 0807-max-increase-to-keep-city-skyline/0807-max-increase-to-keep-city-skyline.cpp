class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRow(n, 0), maxCol(n, 0);

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                maxRow[r] = max(maxRow[r], grid[r][c]);
                maxCol[c] = max(maxCol[c], grid[r][c]);
            }
        }

        int totalIncrease = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                totalIncrease += min(maxRow[r], maxCol[c]) - grid[r][c];
            }
        }

        return totalIncrease;
    }
};