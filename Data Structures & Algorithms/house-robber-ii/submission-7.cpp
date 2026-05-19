
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> max_cost1(n,0);
        max_cost1[0] = nums[0];
        max_cost1[1] = max(nums[0],nums[1]);
         for(int i = 2; i <= n-2; i++){
            max_cost1[i] = max(max_cost1[i-1], max_cost1[i-2] +  nums[i]);
        }
        vector<int> max_cost2(n,0);
        max_cost2[1] = nums[1];
        max_cost2[2] = max(nums[1],nums[2]);
        for(int i = 3; i <= n-1; i++){
            max_cost2[i] = max(max_cost2[i-1], max_cost2[i-2] + nums[i]);
        }
        return max(max_cost1[n-2],max_cost2[n-1]);
    }
};
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         if (n == 1) return nums[0];
//         if (n == 2) return max(nums[0], nums[1]);

//         // Case 1: Rob houses from index 0 to n-2 (include first, exclude last)
//         vector<int> max_cost1(n, 0);
//         max_cost1[0] = nums[0];
//         max_cost1[1] = max(nums[0], nums[1]);
//         for (int i = 2; i <= n - 2; i++) {
//             max_cost1[i] = max(max_cost1[i - 1], max_cost1[i - 2] + nums[i]);
//         }

//         // Case 2: Rob houses from index 1 to n-1 (exclude first, include last)
//         vector<int> max_cost2(n, 0);
//         max_cost2[1] = nums[1];
//         max_cost2[2] = max(nums[1], nums[2]);
//         for (int i = 3; i <= n-1; i++) {
//             max_cost2[i] = max(max_cost2[i - 1], max_cost2[i - 2] + nums[i]);
//         }

//         return max(max_cost1[n - 2], max_cost2[n - 1]);
//     }
// };

