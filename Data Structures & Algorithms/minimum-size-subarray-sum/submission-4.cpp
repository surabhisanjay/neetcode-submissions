class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int curr_win = 0;
        int win_size = 1;
        int min_win = 10000;
        int l = 0;
        int toggle = 0;
        int r = 0;
        for(int r = 0; r < n; r++){
            curr_win += nums[r];
            while(curr_win >= target){
                toggle = 1;
                min_win = min(min_win, r-l+1);
                curr_win -= nums[l];
                l++;
                
            }
        }    
        return toggle != 1? 0: min_win;
    }
};