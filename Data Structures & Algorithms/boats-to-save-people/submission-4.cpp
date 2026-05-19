class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> weights(limit+1,0);
        int no_boats = 0;
        sort(people.begin(),people.end());
        int l = 0; 
        int r = people.size()-1;
        while(l<=r){
            int rem_weight = limit - people[r--];
            no_boats++;
            if(l<=r && people[l] <= rem_weight){
                l++;
            }
        }
        
        return no_boats;
            
    }        
};

        
