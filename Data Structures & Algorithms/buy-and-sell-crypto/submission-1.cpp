class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = 0;
        int l = 0;
        int r = 0;
        while(r< n){
            if(prices[l]<prices[r]){
                int profit = prices[r]-prices[l];
                maxP = max(profit, maxP);

            }
            else{
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
