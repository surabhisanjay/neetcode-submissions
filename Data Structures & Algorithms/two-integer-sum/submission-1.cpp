class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m ;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(m.find(complement) != m.end()){
                return {min(m[complement],i),max(m[complement],i)};
            }
            m[nums[i]] = i;

        }
        return {};
        }
        
    };
