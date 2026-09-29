class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0, right=nums.size()-1;
        int min_ans = INT_MAX;
        while(left <= right){
            int mid=left+(right-left)/2;
            if(nums[left] <= nums[mid]){
                //the left part it sorted so pick store first element of this sorted part      and elemenate the left side and move left to mid + 1 
                min_ans=min(min_ans, nums[left]);
                left=mid+1;
            }else{
                //right part is sorted
                min_ans=min(min_ans, nums[mid]);
                right=mid-1;
            }
        }
        return min_ans;
    }
};
