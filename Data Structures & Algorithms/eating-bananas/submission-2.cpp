class Solution {
public:

    bool isValid(int rate, vector<int>&piles, int h, int n){
        long long hours=0;
        for(int i=0; i<n; i++){
            hours+=(long long)(piles[i]+rate-1)/rate;
        }
        if(hours<=h){
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int min_speed=1;
       
        int max_speed=INT_MIN;
        for(int i=0; i<piles.size(); i++){
            max_speed=max(max_speed, piles[i]);
        }
        int left=1, right=max_speed;

        int min_rate=max_speed;
        while(left <= right){
            int mid=left+(right-left)/2;
            if(isValid(mid, piles, h, n)){
                min_rate=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return min_rate;
        
    }
};
