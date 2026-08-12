class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans(nums);
        int p=nums.size()-1;
        while(p>=0)
        {
            ans.push_back(nums[p--]);
        }

        return ans;
    }
};