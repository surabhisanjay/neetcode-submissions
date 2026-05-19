class Solution {
public:
   
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n){
            k = k%n;
        }
    
        unordered_map<int,int> num_index;
        for(int i = 0; i < nums.size();i++){
            num_index[i] = nums[i];
        }
        for(int i = 0, l = k; i < k && l >= 0; i++, l--){
            nums[i] = num_index[n-l];
        }
        int j = k;
        for(int i = 0; i <= n - k && j < n; i++ ){
            nums[j] = num_index[i];
            j++;
        }
    }
};