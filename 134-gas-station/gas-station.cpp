class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalTank = 0;
        int currentTank = 0;
        int startIndex = 0;

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            totalTank += diff;
            currentTank += diff;

            if (currentTank < 0) {
                startIndex = i + 1;
                currentTank = 0;
            }
        }

        return totalTank >= 0 ? startIndex: -1;
    }
};