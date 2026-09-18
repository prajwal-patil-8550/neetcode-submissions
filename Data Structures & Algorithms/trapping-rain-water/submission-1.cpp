class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>right_max(n, 0);
        vector<int>left_max(n, 0);
        int total_water=0;
        left_max[0]=0;
        for(int i=1; i<n; i++){
            left_max[i]=max(left_max[i-1], height[i-1]);
        }
        right_max[n-1]=0;
        for(int i=n-2; i>=0; i--){
            right_max[i]=max(right_max[i+1], height[i+1]);
        }
        for(int i=0; i<n; i++){
            int water=min(left_max[i], right_max[i])-height[i];
            if(water < 0)   water=0;
            total_water+=water;
        }
        return total_water;
    }
};
