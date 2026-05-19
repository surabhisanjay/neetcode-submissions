class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int win_size = 0;
        int new_index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[new_index] = nums[i];
                new_index++;
            }

        }
        return new_index;
    }
};