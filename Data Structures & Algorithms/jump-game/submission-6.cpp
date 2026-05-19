class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int jump = 0;
        int count = 0;
        int goal = nums.size()-1;
        int n = nums.size();
        
        vector<bool> dp(n,false);
        dp[n-1]= true;
        for(int i = n-2; i >= 0; i--){
            int end = min((int)nums.size(),i+nums[i]+1);
            for(int j = i+1 ; j < end; j++){
                if(dp[j]){
                    dp[i]= true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
