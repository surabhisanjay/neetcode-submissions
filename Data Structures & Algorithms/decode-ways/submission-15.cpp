class Solution {
public:
    // int memo(string s, int i){
        
    //     if(s[i] == '0'){
    //         return 0;
    //     }
    //     if(i == s.length()){
    //         return 1;
    //     }
    //     int max_num = memo(s, i + 1);
    //     if(i+1 < s.length()) {
    //         if(s[i]=='1' || s[i]=='2' && s[i+1]<'7'){
    //             max_num += memo(s,i+2);
    //         }  
    //     }
        
    //     return max_num; 
    // }
    // int numDecodings(string s) {
        
    //     int max_num = memo(s,0);
    //     return max_num;
        
    // }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n]=1;

        int i = n-1;
        while(i>=0){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else {
                dp[i] += dp[i+1];
                if(i+2 <= s.length()){
                    if(s[i] == '1' || s[i]=='2' && s[i+1]<'7'){
                        dp[i] += dp[i+2];
                    }  
                }
            }  
            
            i--;
        }
        return dp[0];
    }
};
