class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> s;
        for(int i:friends)
        {
            s.insert(i);
        }
        vector<int>ans;
        for(int i:order)
        {
            if(s.find(i)!=s.end())
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};