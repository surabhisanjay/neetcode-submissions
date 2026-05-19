class Solution {
public:
    string expand_around_center(string s, int left, int right){
        while(left >= 0 && right < s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
        
    string longestPalindrome(string s) {
        int mid = s.length()/2;
        string max = "";
        for(int i = 0; i < s.length(); i++){
            string longest_odd = expand_around_center(s,i,i);
            string longest_even = expand_around_center(s,i,i+1);
            if(longest_odd.length() > max.length()){
                max = longest_odd;
            }
            if(longest_even.length() > max.length()){
                max = longest_even;
            }
        }
      
        
        return max;

    }
};
