class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int currProfit = 0;
        int l = 0;
        int minPrice = INT_MAX;
        for(int b = 1; b < prices.size(); b++){
           if(prices[b]>prices[b-1]){
                maxprofit+= prices[b]-prices[b-1];
           }
        }
        return maxprofit;
    }
};