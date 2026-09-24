class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int>ans;
        //for first window
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k; i< nums.size(); i++){
            ans.push_back(nums[dq.front()]);
            //we remove elements which are before the window
            while(!dq.empty() && dq.front() < i-k+1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};
