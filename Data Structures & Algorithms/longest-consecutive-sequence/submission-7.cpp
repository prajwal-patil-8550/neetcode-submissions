class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int count=0, maxCount=0;
        // if(nums.size()==0){
        //     return 0;
        // }
        // set<int>st;
        // for(int i=0; i<nums.size(); i++){
        //     st.insert(nums[i]);
        // }
        // for(auto num : st){
        //     if(st.count(num-1)){
        //         continue;
        //     }else{
        //         while(st.count(num+1)){
        //             count++;
        //             maxCount=max(maxCount, count);
        //             num+=1;
        //         }
        //         count=0;
        //     }
        // }
        // return maxCount+1;
        unordered_set<int>st(nums.begin(), nums.end());
        
        
        int max_count=0;
        for(int num : st){
            int count=1;
            if(st.find(num-1) == st.end()){
                //element-1 is not in the map hence its the starting of a sequence
                int next = num+1;
                while(st.find(next) != st.end()){
                    count++;
                    next=next+1;
                }
                max_count=max(max_count, count);
            }
        }
        return max_count;
    
    }
};
