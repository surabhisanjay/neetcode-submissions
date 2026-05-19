class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.length()!=s.length()){
            return false;
        }
        std::map<char, int> sf;
        std::map<char, int> tf;
        for(int i = 0; i < s.length(); i++){
            sf[s[i]] += 1;
            tf[t[i]] += 1;
        }
        for(int i = 0; i < t.length(); i++){
            if(sf.find(t[i]) != sf.end()){
                if(sf[t[i]] != tf[t[i]]){
                    return false;
                }
            }
            else{
                return false;
            }
            
        }
    return true ;
    }

};

