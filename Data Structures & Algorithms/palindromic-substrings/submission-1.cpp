class Solution {
public: 
    int expand_around_center(int left, int right, const string &s){
            vector<int> indices;
            int count = 0;
            while(left>= 0 && right <= s.length()- 1 && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
            
            return count;
    }
    int countSubstrings(string s) {
        unordered_map<int, int> centers;
        if(s.length() == 0){
            return 0;
        }
        int count = 1;
        for(int i = 0; i < s.length()-1; i++){
            count += expand_around_center(i,i,s);
            count += expand_around_center(i,i+1,s);
            
        }
        
        return count;
    }
};
