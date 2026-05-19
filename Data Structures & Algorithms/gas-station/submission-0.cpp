class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int max_gas = 0;
        int max_i = 0;
        int n= gas.size();
        int tank = 0;
        int total = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            int gain = gas[i]-cost[i];
            tank += gain;
            total += gain;
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        return total >= 0?start:-1;
    }
};
