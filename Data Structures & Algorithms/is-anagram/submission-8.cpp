class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()){
            return false;
        }
        vector<int> count_alphabets(26,0);
        for(int i = 0; i < s.length(); i++){
            count_alphabets[s[i]-'a']++;
            count_alphabets[t[i]-'a']--;

        }
        for(int i = 0; i < count_alphabets.size(); i++){
            if(count_alphabets[i]!= 0){
                return false;
            }
        }
        return true;

    }

};

