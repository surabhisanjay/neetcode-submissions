class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int r = 0;
        int maxProduct = nums[0];
        int currProduct = nums[0];
        int maxProd= nums[0];
        int minProduct =nums[0]; 
        for(int r = 1; r < n; r++){
            if(nums[r]<0){
                swap(currProduct,minProduct);
            }
            currProduct = max(currProduct*nums[r],nums[r]);
            minProduct = min(minProduct*nums[r],nums[r]);
            maxProd = max(currProduct,maxProd);

            
        }
        return maxProd;
    }
};
