class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> num_freq;
        vector<int> result;
        for(const auto& i : nums){
            num_freq[i]++;
            
        }
        vector<pair<int, int>> vec(num_freq.begin(), num_freq.end());
        sort(vec.begin(), vec.end(),[](const pair<int, int> &a,const pair<int, int> &b ){ return a.second > b.second;});
        int i = 0;
        int index = vec.size();
        while(i < k){
            result.push_back(vec[i].first);
            i++;
        }
        return result;
    }
};
