class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> indices(nums.size(),-1);

        for(int num: nums){
            if(indices[num-1] == 0){
                return num;
            }
            indices[num-1] = 0;
        }
        return -1;

    }
};
