class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int i = 0;
        while(i < s.length()){
            if(s[i] == '['||s[i] == '{'||s[i] == '('){
                stack.push_back(s[i]);
            }
            else{
                if (stack.empty()) return false;  
                if ((s[i] == ')' && stack.back() != '(') || (s[i] == ']' && stack.back() != '[') || (s[i] == '}' && stack.back() != '{')){
                    return false;
                }
                stack.pop_back();
            }
            
            i++;
        }
        return stack.empty();
    }
};
