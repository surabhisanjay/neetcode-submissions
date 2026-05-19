
class Solution {
public:
int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        vector<int> max_prices(n+1,0);
        max_prices[0] = 0;
        max_prices[1] = nums[start];
        int i = 2;
        while(i <= n){
            max_prices[i] = max(max_prices[i-1],max_prices[i-2]+nums[start+ i -1]);
            i++;
        }
        return max_prices[n];

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int money1 = robRange(nums,0,n-2);
        int money2 = robRange(nums,1,n-1);

        return max(money1,money2);
    }
};

