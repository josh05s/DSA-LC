class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lo = prices[0];
        int hi = prices[0];
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lo) {
                lo = prices[i]; 
                hi = prices[i];
            }
            if (prices[i] > hi) hi = prices[i];
            if (hi - lo > profit) profit = hi - lo;        }

        return profit;
    }
};