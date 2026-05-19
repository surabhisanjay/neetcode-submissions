class Solution {
public:
    void reverseString(vector<char>& s) {
        unordered_map<int, char> letter_index;
        for(int i = 0; i < s.size(); i++){
            letter_index[i] = s[i];
        }
        int n = s.size();
        for(int i = n-1; i >=0; i--){
            s[i] = letter_index[n-1-i];
        }
    }
};