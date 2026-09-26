class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>cars;
        for(int i=0; i<position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        //sorts the array by first value of pair whih is position in this case 
        sort(cars.begin(), cars.end());     
        stack<float>st; //as time could be in decimals like 4.5 hrs
        for(int i=cars.size()-1; i>=0; i--){
            float time= (float)(target-cars[i].first)/cars[i].second;
            if(!st.empty() && time <= st.top()){
                continue;
            }
            st.push(time);
        }
        return st.size();
    }
};
