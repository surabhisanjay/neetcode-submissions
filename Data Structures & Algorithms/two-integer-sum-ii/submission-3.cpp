class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> num_map;
        vector<int> indices; 
        int smaller;
        int bigger;
        for(int i = 0; i < numbers.size(); i++){
            num_map[numbers[i]] = i;
            if(num_map.find(target-numbers[i])!= num_map.end()){
                smaller = min(num_map[target-numbers[i]],num_map[numbers[i]]);
                bigger = max(num_map[target-numbers[i]],num_map[numbers[i]]);
            }

        }
        indices.push_back(smaller+1);
        indices.push_back(bigger+1);
        return indices;
    }
};
