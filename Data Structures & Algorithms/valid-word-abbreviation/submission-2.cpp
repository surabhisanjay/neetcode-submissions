class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int n2 = abbr.length();
        int n1 = word.length();
        while(i < n1 && j < n2){
            if(isalpha(abbr[j]) ){
                if(word[i] != abbr[j]){
                    return false;
                }
                i++;
                j++;
            }
            else if (isdigit(abbr[j])){
                if (abbr[j] == '0') return false;
                int num = 0;
                while(isdigit(abbr[j]) && j < n2){
                    num = num * 10 + (abbr[j]-'0');
                    j++;
                }
                i += num;
            }
            else{
                return false;
            }
        }
        return i == n1 && j == n2;
    }
};