class Solution {
public:
    int characterReplacement(string s, int k) {
        int no_replacements = 0; 
        int l = 0;
        int r = 1;
        int n = s.length();
        int max_window = 0;
        int i = 0;
        int res = 0;
        unordered_map<char,int> count;
        char window_value=s[0];
        int maxf = 0;

        for(int r = 0; r < s.size();r++){
            count[s[r]]++;
            maxf = max(maxf,count[s[r]]);
            while((r-l+1)-maxf > k){
                count[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};
