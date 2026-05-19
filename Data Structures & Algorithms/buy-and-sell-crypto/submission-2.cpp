class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int s = 0;
        
        int curr_profit = 0;
        int min_price = INT_MAX;
        int b = 0;
        while(s < prices.size()){
            min_price = min(prices[b], min_price); //minimum buying price
            int profit = prices[s] - min_price;
            if(profit > max_profit){
                max_profit = profit;
                b = s;
            }
            else{
                b++;
            }
            s++;
        }
        return max_profit;
    }
};
