class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        int total = 0;
        vector<int> stk;
        int i = 0;
        while(i<tokens.size()){
                string ele = tokens[i];
                if (ele == "+"){
                    int sum = 0;
                    int ele1 = stk.back(); stk.pop_back();
                    int ele2 = stk.back(); stk.pop_back();
                    sum = (ele2+ele1);
                    stk.push_back(sum);
                }
                else if (ele == "-"){
                    int sum = 0;
                    int ele1 = stk.back(); stk.pop_back();
                    int ele2 = stk.back(); stk.pop_back();
                    sum = (ele2-ele1);
                    stk.push_back(sum);
                    
                }
                else if( ele == "/"){
                    int sum = 0;
                    int ele1 = stk.back(); stk.pop_back();
                    int ele2 = stk.back(); stk.pop_back();
                    sum = (ele2/ele1);
                    stk.push_back(sum);
                }
                else if (ele == "*"){
                    int sum = 0;
                    int ele1 = stk.back(); stk.pop_back();
                    int ele2 = stk.back(); stk.pop_back();
                    sum = (ele2*ele1);
                    stk.push_back(sum);
                }
                else{
                    stk.push_back(stoi(ele));
                }
            i++;
        }
        return stk.back();
        
    }
};
