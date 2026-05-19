class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; 
        int r = 0;
        int n = s.length();
        unordered_set<char> visited;
        int max_length = 0;
        while(r<n){
            while(visited.find(s[r])!=visited.end()){
               visited.erase(s[l]);
               l++;
                
            }
            visited.insert(s[r]);
            max_length = max(max_length,r-l+1);
            r++;
        }
        return max_length;
    }
};
