class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left <= right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            //left is sorted
            else if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target <= nums[mid]){
                    //it lies in left part
                    right=mid-1;
                }else{
                    //it does not lie on the sorted side so move to the right
                    left=mid+1;
                }
            }else{  //right is sorted
                if(target >= nums[mid] && target <= nums[right]){
                    //it lies in the sorted part 
                    left=mid+1;
                }else{
                    //it lies on the left unsorted part
                    right=mid-1;
                }

            }
        }
        return -1;
    }
};
