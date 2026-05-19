class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> final_ans = nums;
        for(int i = 0; i < nums.size(); i++){
            final_ans.push_back(nums[i]);

        }
        return final_ans;
    }
};