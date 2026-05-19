class KthLargest {
public:
    int k;
    vector<int> nums;
    priority_queue<int,vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
         for(int num: nums){
            minHeap.push(num);
            while(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size() > k){
                minHeap.pop();
        }
        return minHeap.top();
    }
};
