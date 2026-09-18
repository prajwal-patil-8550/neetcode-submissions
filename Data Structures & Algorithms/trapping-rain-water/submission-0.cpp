class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>right_max(n, 0);
        vector<int>left_max(n, 0);
        int total_water=0;
        int l_max=0;
        for(int i=1; i<n; i++){
            l_max=max(l_max, height[i-1]);
            left_max[i]=l_max;
        }
        int r_max=0;
        for(int i=n-2; i>=0; i--){
            r_max=max(r_max, height[i+1]);
            right_max[i]=r_max;
        }
        for(int i=0; i<n; i++){
            int water=min(left_max[i], right_max[i])-height[i];
            if(water < 0)   water=0;
            total_water+=water;
        }
        return total_water;
    }
};
