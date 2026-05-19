class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colours(3,0);
        int max_num;
        for(int num: nums){
            colours[num]++;
        }
        int k =0;
        for(int i = 0; i < colours.size();i++){
            for(int j = 0; j < colours[i]; j++){
                nums[k++] = i;
            }
        }
    
    }
};