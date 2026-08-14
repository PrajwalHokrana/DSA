class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s; // index
        vector<int> ans(n, -1);

        for (int i = 0; i < 2 * n -1; i++) {
            int idx = i % n;

            while (!s.empty() && nums[idx] > nums[s.top()]) {
                ans[s.top()] = nums[idx];
                s.pop();
            }

            if (ans[idx] == -1)
                s.push(idx);
        }

        return ans;
    }
};