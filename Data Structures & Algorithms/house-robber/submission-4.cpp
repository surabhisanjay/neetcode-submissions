class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_cost(n+1);
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        max_cost[0] = nums[0];
        max_cost[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            max_cost[i] = max(max_cost[i-1], max_cost[i-2]+nums[i]);
        }
        return max_cost[n-1];
    }
};

