class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charfreq;
        int ans = 0;
        int maxcount = 0;
        vector<int> count(26, 0);
        int l = 0, maxfreq = 0;
        for (int r = 0; r < s.length(); r++){
            count[s[r]-'A']++;
            maxcount = max(maxcount, count[s[r]-'A']);
            while(((r-l+1) - maxcount ) > k){
                count[s[l]-'A']--;
                l++;
                
            }
            ans = max(ans,r-l+1);
            
        }
        return ans;
    }
    
};
