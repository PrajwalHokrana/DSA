class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // Map to store the number(key) and its original index(value)
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i]) == m.end())
            {
                m[nums[i]]=i;
            }
            else{
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }

        return ans;
    }
};