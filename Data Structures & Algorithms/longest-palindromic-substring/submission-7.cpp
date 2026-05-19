class Solution {
public:

    vector<int> expand_around_center(int left, int right, const string &s, int *maxlen){
        vector<int> indices;
        while(left>= 0 && right <= s.length()- 1 && s[left] == s[right]){
            left --;
            right++;
        }
        left++;
        right--;
        return {right - left + 1,left,right};
    }
    string longestPalindrome(string s) {
        int maxlen = 0;
    
        vector<int> max_indices={0,0,0};
        
        for(int i = 0; i < s.length(); i++){
            vector<int> len1 = expand_around_center(i, i, s,&maxlen);
            vector<int> len2 = expand_around_center(i, i+1, s, &maxlen);
            if(max_indices[0] < len1[0]){
                max_indices = len1;
            }
            if(max_indices[0] < len2[0]){
                max_indices = len2;
            }
        }
        return s.substr(max_indices[1],max_indices[0]);
    }
};
