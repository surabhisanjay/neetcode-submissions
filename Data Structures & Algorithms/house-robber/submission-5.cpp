class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_prices(n+1,0);
        max_prices[0] = 0;
        max_prices[1] = nums[0];
        int i = 2;
        while(i <= n){
            max_prices[i] = max(max_prices[i-1],nums[i-1]+max_prices[i-2]);
            i++;
        }
        return max_prices[n];
    }
};

