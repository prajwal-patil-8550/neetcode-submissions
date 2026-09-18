class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;   //number->index
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                //we found complement in the map -> complement=target-nums[i]
                return {mp[target-nums[i]], i};
            }else{
                //if we dont find it in map then store the prev nums in 
                mp[nums[i]]=i;
            }
        }
        return {};
    }
};
