class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window_size = 0;
        int window= 0;
        int l = 0;
        int min_window = INT_MAX;
        for(int r = 0; r < nums.size(); r++){
            window += nums[r];
            while(window >= target){
                min_window = min(min_window, r-l+1);
                window -= nums[l];
                l++;
            }
        }

        return min_window == INT_MAX?0:min_window;
    }
};