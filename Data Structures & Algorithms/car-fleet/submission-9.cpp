class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort cars by starting position in descending order
        sort(cars.begin(), cars.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        });
        vector<double> stack;
        for(auto& car : cars) {
            double time = (double)(target - car.first) / car.second;

            if(stack.empty() || time > stack.back()) {
                stack.push_back(time);  // New fleet
            }
            // Else, the car joins the previous fleet (no push)
        }

        return stack.size();
    }
};
