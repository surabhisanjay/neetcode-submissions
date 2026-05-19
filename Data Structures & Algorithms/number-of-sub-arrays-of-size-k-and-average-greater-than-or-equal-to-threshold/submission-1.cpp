class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int r = k-1;
        int res = 0;
        int curr_window = 0;
        int n = arr.size();
        for(int i = 0; i < k-1; i++){
            curr_window += arr[i];
        }
        while(r < n){
            curr_window += arr[r];
            if(curr_window/k >= threshold){
                res++;
            }
            curr_window -= arr[l];
            r++;
            l++;
        }
        return res;
    }
};