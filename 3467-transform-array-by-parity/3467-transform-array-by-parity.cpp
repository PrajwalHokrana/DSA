class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int evenCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                evenCount++;
            }
        }

        // Fill in-place: first evenCount elements are 0, rest are 1
        fill(nums.begin(), nums.begin() + evenCount, 0);
        fill(nums.begin() + evenCount, nums.end(), 1);

        return nums;
    }
};