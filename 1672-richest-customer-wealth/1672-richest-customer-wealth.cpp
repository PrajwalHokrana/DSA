class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (auto customer : accounts) {
            int currentSum = 0;
            for (int bank : customer) {
                currentSum += bank;
            }
            maxWealth = max(maxWealth, currentSum);
        }
        return maxWealth;
    }
};