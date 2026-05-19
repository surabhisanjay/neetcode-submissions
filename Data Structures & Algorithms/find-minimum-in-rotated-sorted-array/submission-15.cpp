class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = 0;
        int r = nums.size() - 1;
        int mid=0;
        // Handle the case when the array is not rotated
        if (nums[l] <= nums[r]) {
            return nums[l];
        }
        while(l<=r){
            mid = l + (r-l)/2;
            if(mid > 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            if(mid < nums.size() - 1 && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }


            if(nums[l] <= nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }

        }
        return -1;
    }
};
