class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> char_freq;
        for(string s: strs){
            vector<int> chars(26,0);
            for(char c: s){
                chars[c -'a']++;
            }
            string char_string(chars.begin(), chars.end());
            char_freq[char_string].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it= char_freq.begin();it!=char_freq.end();it++) {
            result.push_back(it->second);
        }
        return result;
    }
};
