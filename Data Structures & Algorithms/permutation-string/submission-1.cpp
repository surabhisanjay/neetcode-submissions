class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1>n2){
            return false;
        }
        vector<int> s1_freq(26,0);
        vector<int> s2_freq(26,0);
        vector<int> window_freq(26,0);
        for(int i = 0;i < n1; i++){
            s1_freq[s1[i]-'a']++;
        }
        int l = 0;
        int running_freq = 0;
        for(int r = 0; r < n2; r++){
            window_freq[s2[r]-'a']++;
            if(r - n1>=0){
                window_freq[s2[r - n1]-'a']--;
            }
            
            if(window_freq == s1_freq){
                return true;
            }

        }
        return false;
               
        }
    
};
