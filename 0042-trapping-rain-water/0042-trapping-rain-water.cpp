class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, lmax = 0, rmax = 0, l = 0, r = n - 1;
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans += (lmax - height[l++]);
            } else {
                ans += (rmax - height[r--]);
            }
        }
        return ans;
    }
};