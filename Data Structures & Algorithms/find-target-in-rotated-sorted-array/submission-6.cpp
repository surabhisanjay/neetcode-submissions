class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size()-1;
        int mid;
        if(nums[l]<nums[r]){
                while(l<=r){
                    mid = l+ (r-l)/2;
                    if(nums[mid]==target){
                        return mid;
                    }
                    else if(nums[mid]>target){

                        r = mid -1;
                    }
                    else{

                        l = mid + 1;
                    }
                }
        }
        while(l<=r){
            //pivot element is found
            mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] <= nums[r]){ //right half is sorted
                if(target <= nums[r] && target >= nums[mid]){
                    l = mid+1;
                }
                else{
                    r = mid -1;
                }
            }
            else if(nums[mid]>= nums[l]){ //left half is sorted
                if(target <= nums[mid] && target >= nums[l] ){
                    r = mid -1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }      
};
