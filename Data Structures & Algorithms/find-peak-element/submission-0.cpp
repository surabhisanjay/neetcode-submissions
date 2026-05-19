class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        int peak = 0;
        int n = nums.size();
        for(int i = 1; i < nums.size();i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                return i;
            }
            if(nums[i] < nums[i-1] && nums[i] > nums[i+1]){
                i++;
            }
        }
        return peak;
    }
};