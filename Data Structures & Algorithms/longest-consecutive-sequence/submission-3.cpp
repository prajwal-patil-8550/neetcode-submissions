class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0, maxCount=0;
        if(nums.size()==0){
            return 0;
        }
        set<int>st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        for(auto num : st){
            if(st.count(num-1)){
                continue;
            }else{
                while(st.count(num+1)){
                    count++;
                    maxCount=max(maxCount, count);
                    num+=1;
                }
                count=0;
            }
        }
        return maxCount+1;
    }
};
