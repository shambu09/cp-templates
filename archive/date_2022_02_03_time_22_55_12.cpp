class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        
        int buy = prices[0], sell = prices[1] - prices[0];
        
        for(int i = 1; i <= prices.size() - 1; i++){
            sell = max(sell, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        
        return max(sell, 0);
    }
};