class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0; 
        int maxL = 0;
        unordered_set<char> uset;
        while(r < s.length()){ 
            while(uset.find(s[r]) != uset.end()){
                uset.erase(s[l]);
                l++;
            }
            uset.insert(s[r]);
            maxL = max(r-l+1,maxL);
            r++;
        }

        return maxL;
    }
};
