class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int min_price = prices[0];
        for(int i = 0; i < prices.size(); i++){ // is the selling price
            min_price = min(prices[i],min_price);
            int currProfit = prices[i] - min_price;
            maxProfit  = max(maxProfit, currProfit);
        }
        return maxProfit;
    }
};
