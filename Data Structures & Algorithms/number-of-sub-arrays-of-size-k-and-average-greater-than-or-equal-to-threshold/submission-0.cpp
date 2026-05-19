class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int n = arr.size();
        int i = 0;
        int initial_sum = 0;
        while(i<k-1){
            initial_sum += arr[i];
            i++;
        }
        int l = 0; 
        int r = 2;
        int curr_avg = 0;
        int curr_sum = initial_sum;
        int curr_size = 0;
        for(int l = 0; l < n-k+1; l++){
            curr_sum += arr[l+k-1];
            if(curr_sum/k >= threshold){
                res++;
            }
            curr_sum-= arr[l];
        }
        return res;
    }
};