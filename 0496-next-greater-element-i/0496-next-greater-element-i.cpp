class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]]=-1;
            if(!s.empty())
            {
                while(!s.empty() && nums2[i]>s.top())
                {
                    m[s.top()]=nums2[i];
                    s.pop();
                }
            }

            s.push(nums2[i]);
        }

        for(int i:nums1)
        {
            ans.push_back(m[i]);
        }


        return ans;
    }
};