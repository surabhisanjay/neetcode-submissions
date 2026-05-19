class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result;
        int zeroth_product ;
        int non_zero_product=1;
        bool has_zero = false;
        int sum = 0;
        int zero_count = 0;
        bool has_anything_but_zero = false;
        for(int i : nums){

            if(i == 0){
                zero_count++;

            }
            else{
                non_zero_product *= i;
            }


        }
        for(int num : nums){
        
        if(zero_count == 1){
           if(num == 0){
                result.push_back(non_zero_product);
            }
            else{
                result.push_back(0);
            }
        }
        else if(zero_count > 1){
            result.push_back(0);
        }
        else{
            result.push_back(non_zero_product/num);
        }
               
          
        }
        return result;
    }
};
