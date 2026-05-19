class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_freq;
        int n = nums.size();
        vector<int> freq_num(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            num_freq[nums[i]]++;
        }
        for(const auto& pair: num_freq){
            freq_num[pair.second] = pair.first;
        }
        int i = nums.size()-1;
        
        while(i >= n/2){
            if(freq_num[i]!=0){
                return freq_num[i];
            }
            i--;
        }
        return nums[0];
    }
};