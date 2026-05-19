class Solution {
public:
    int maxArea(vector<int>& heights) {
        int r = 0;
        int res = INT_MIN;
        int n = heights.size();
        for(int l = 0; l < heights.size(); l++){
            r = l+1;
            while(r < n){
                int height = min(heights[l],heights[r]);
                res = max(res,height*(r-l));
                r++;
            }
        }
        return res;    
    }
};
