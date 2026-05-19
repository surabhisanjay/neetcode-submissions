class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest_prefix = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0; 
            for(int j = 0; j < strs[0].length(); j++){
                while(j < min(longest_prefix.length(), strs[i].length())){
                    if(longest_prefix[j]!= strs[i][j]){
                        break;
                    }
                    j++;
                }
                longest_prefix = longest_prefix.substr(0,j);
            }
            
        }
        return longest_prefix;
        
    }
};