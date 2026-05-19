class Solution {
public:
    
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int , int> num_freq;
        for(int i : nums){
            num_freq[i]++;

        }
        for(const auto &pair : num_freq){
            bucket[pair.second].push_back(pair.first); 
        }
        vector <int> result;
        for(int i = nums.size(); result.size()<k && i >= 0; i--){
            for(int j : bucket[i]){
                result.push_back(j);
                if(result.size()==k){
                    break;
                }
            }
        }
        return result;

        
    }
};
