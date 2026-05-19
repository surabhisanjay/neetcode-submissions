class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int min_temp = 1000; 
        vector<int> result(temperatures.size(),0);
        vector<int> stk;
        for(int i = 0; i < temperatures.size(); i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.back()]){
                int top = stk.back();
                stk.pop_back();
                result[top] = i - top;
            }
            stk.push_back(i);
        }
        return result;
    }
};
