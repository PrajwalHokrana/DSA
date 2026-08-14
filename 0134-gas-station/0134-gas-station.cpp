class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totCost = 0, currentGas = 0, start = 0, n = gas.size();

        for (int i = 0; i < n; i++) {
            totGas += gas[i];
            totCost += cost[i];
            currentGas += (gas[i] - cost[i]);
            if (currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }
        if (totGas < totCost) {
            return -1;
        }
        return start;
    }
};