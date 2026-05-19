class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> numbers;
        int i = 0;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            numbers[nums[i]] = i;
        }
        int count = 0;
        int max_count = 0;
        while(i < n){
            int ind = 1;
            int count = 1;
            while(numbers.find(nums[i]+ind)!= numbers.end()){
                ind++;
                count++;
            }
            max_count = max(max_count, count);
            i++;
        }
        return max_count;
    }
};
