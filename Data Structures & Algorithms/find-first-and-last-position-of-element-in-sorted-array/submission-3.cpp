class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int mid;
        if(nums.size() == 0){
            return vector<int> {-1,-1};
        }
        while(l<r){
            mid = l + (r-l)/2;
            if(nums[mid] == target){
                int start = l;
                int end = r;
                while(nums[start]!=target){
                    start++;
                }
                while(nums[end]!=target){
                    end--;
                }
                return vector<int> {start,end};
            }
            else if(nums[mid] > target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return vector<int> {-1,-1};
    }
};