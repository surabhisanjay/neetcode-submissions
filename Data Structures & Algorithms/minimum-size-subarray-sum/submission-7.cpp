class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int r = 0;
        int sum = 0;
        int minlen = INT_MAX;
        int size = 0;
        bool found = false;
        while(r < n){
            sum += nums[r];
            if(sum >= target){
                found = true;
                while(sum >= target){
                    minlen = min(r-l+1,minlen);
                    sum -= nums[l];
                    l++;
                }
                
            }
            r++;
        }
        return found?minlen: 0;
    }
};