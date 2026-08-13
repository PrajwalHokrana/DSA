class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot); // Initialize whole array with pivot
        
        int left = 0;
        int right = n - 1;

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            if (nums[i] < pivot) {
                ans[left++] = nums[i];
            }
            if (nums[j] > pivot) {
                ans[right--] = nums[j];
            }
        }

        return ans;
    }
};