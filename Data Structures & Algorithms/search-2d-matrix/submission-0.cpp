class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            int left=0, right=matrix[0].size()-1;
            while(left <= right){
                int mid=left+(right-left)/2;
                if(matrix[i][mid]==target){
                    return true;
                }
                else if(matrix[i][mid] > target){
                    right=mid-1;
                }
                else if(matrix[i][mid] < target){
                    left=mid+1;
                }
            }
        }
        return false;
    }
};
