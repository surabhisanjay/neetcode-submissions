class Solution {
public:
    void swap(int* a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;

    }
    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> arr;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);
        
        for(int i = 0; i < n1; i++){
            L[i] = nums[left + i];
        }
        for(int j = 0; j < n2; j++){
            R[j] = nums[j + 1 + mid ];
        }
        int i = 0; 
        int j = 0;
        int k = left;
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                nums[k] = L[i];
                i++;
            }
            else{
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k] = R[j];
            j++;
            k++;
        }
        
    }

    void mergesort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        int mid = left + (right-left)/2;
        mergesort(nums, left, mid);
        mergesort(nums, mid+1, right);
        merge(nums,left, mid, right);

    }
    
    vector<int> sortArray(vector<int>& nums) {
       mergesort(nums,0,nums.size()-1);
       return nums;
    }
};