class Solution {
public:


    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> indices;
        indices[0] = 1;
        int currsum= 0;
        for(int i = 0; i < nums.size(); i++){
            currsum += nums[i];
            int diff = currsum - k;
            res += indices[diff];
            indices[currsum]++;
        }
        return res;
    }
};