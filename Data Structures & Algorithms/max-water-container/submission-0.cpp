class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0; 
        int r = heights.size() - 1;
        int max_amount = 0;
        int width;
        int lower_bar;
        int curr_amount;
        while(l < r){
            width = r - l;
            lower_bar = min(heights[l],heights[r]);
            curr_amount = lower_bar*width;
            max_amount = max(max_amount, curr_amount);
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
         return max_amount;
    }
   
};
