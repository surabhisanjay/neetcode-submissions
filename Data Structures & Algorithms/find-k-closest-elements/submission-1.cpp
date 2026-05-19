class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       
        int n = arr.size();
        int l = 0, r = n-1;
        int idx = 0;
        //sorted integer array 
    
        for(int i = 0; i < arr.size(); i++){
            if(abs(arr[i]-x) <= abs(arr[idx]-x)){
                idx = i;
            }
        }
        vector<int> closest = {arr[idx]};
        l = idx - 1;
        r = idx +1;
        while(closest.size()<k){
            if(l >= 0 && r < n){
                if(abs(arr[l]-x) <= abs(arr[r]-x)){
                    closest.push_back(arr[l--]);
                }
                else{
                    closest.push_back(arr[r++]);
                }
            }
            else if(l>= 0){
                closest.push_back(arr[l--]);
            }
            else if(r < n){
                closest.push_back(arr[r++]);
            }
        }
        sort(closest.begin(),closest.end());
        return closest;

    }
};