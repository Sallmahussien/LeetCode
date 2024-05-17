class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int profit = 0;

        while(j < prices.size()) {
            int temp_profit = prices[j] - prices[i];
            if (temp_profit < 0) {
                i = j;               
            } else {
                if (temp_profit > profit) profit = temp_profit;
            }
            j++;
        }

        return profit;
    }
};