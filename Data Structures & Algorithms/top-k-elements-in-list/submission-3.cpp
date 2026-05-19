class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for(int num: nums){
            num_freq[num]++;
        }
        int n = nums.size()-1;
       
        int max_freq = 0;
        for(auto it = num_freq.begin(); it != num_freq.end(); it++){
            max_freq = max(max_freq, it->second);
        }
         vector<vector<int>> freq_num(max_freq+1);
        for(auto it = num_freq.begin(); it != num_freq.end(); it++){
            int number = it->first;
            int frequency = it->second;
            freq_num[frequency].push_back(number);
        }
        vector<int> top_k;
        int count= 0;
        for(int i = freq_num.size()-1; count < k; i--){
            if(freq_num.size()>0){
                for(int num: freq_num[i]){
                top_k.push_back(num);
                count++;
                 if(count == k){
                    return top_k;
                }
            }  
        }
              
        }
    }
};
