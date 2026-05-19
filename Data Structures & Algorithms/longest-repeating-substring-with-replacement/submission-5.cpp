class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int l =0;
        int r = 0;
        int count=0;
        unordered_map<char,int> charset;
        char c = s[r];
        for(char c: s){
            int l = 0;
            int count =0;
            for(int r = 0; r < s.length(); r++){
                if(s[r]==c){
                    count++;
                }
                while((r-l+1)-count>k){
                    if(s[l]==c){
                        count--;
                    }
                    l++;
                }
                maxlen = max(maxlen,r-l+1);
            }
        }
        return maxlen;
    }
};
