class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int l = 0; 
        int n = s.length();
        int r = 0;
        int maxl = 0;
        while(r < n){
            
            while(char_set.find(s[r]) != char_set.end()){
                    char_set.erase(s[l]);  
                    l++;  
            }
            char_set.insert(s[r]);
            maxl = max(maxl, r-l+1);
            r++;
        }
        return maxl;
    }
};
