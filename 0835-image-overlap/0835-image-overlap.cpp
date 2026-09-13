class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;

        // 1. Collect coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) v1.push_back({r, c});
                if (img2[r][c] == 1) v2.push_back({r, c});
            }
        }

        // 2. Count frequencies of translation vectors
        // Encode (dr, dc) into a single integer key to avoid pair hashing overhead
        unordered_map<int, int> shiftCount;
        int maxOverlap = 0;

        for (auto [r1, c1] : v1) {
            for (auto [r2, c2] : v2) {
                int key = (r1 - r2 + 100) * 200 + (c1 - c2 + 100);
                shiftCount[key]++;
                maxOverlap = max(maxOverlap, shiftCount[key]);
            }
        }

        return maxOverlap;
    }
};