#include<unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int> &nums) {
        
        std::unordered_set<int> numbers;
        for (int i = 0; i < nums.size(); i++){
        if(numbers.find(nums[i]) == numbers.end()){
            numbers.insert(nums[i]);
        }
        else{
            return true;
        }
        }
        return false;
    }
    
};
