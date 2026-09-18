class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>ans(nums.size(), 1);
       int prefix=1;
       for(int i=1; i<nums.size(); i++){
        prefix=prefix*nums[i-1];
        ans[i]=prefix;
       }
       int suffix=1;
       for(int i=nums.size()-2; i>=0; i--){
        suffix=suffix*nums[i+1];
        ans[i]=ans[i]*suffix;
       }
       return ans;
    }
};
