class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> num_freq;
        unordered_map<int,vector<int>> freq_num;
        vector<int> res;
        int max_freq = INT_MIN;
        for(int num: nums){
            num_freq[num]++;
            max_freq = max(max_freq,num_freq[num]);
        }
      
        for(const auto& pair: num_freq){
            freq_num[pair.second].push_back(pair.first);
        }

        for(int i = max_freq; i>=0;i--){
            for(int n: freq_num[i]){
                res.push_back(n);
                k--;
            }
            if(k <= 0){
                return res;
            }
        }
        return res;
    }

};
