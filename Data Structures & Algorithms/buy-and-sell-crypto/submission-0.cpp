class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lower=prices.size()-1, upper=prices.size()-1;
        int max_profit=INT_MIN;
        while(lower >= 0){
            if(prices[lower] > prices[upper]){
                upper=lower;
            }else{
                int profit=prices[upper]-prices[lower];
                max_profit=max(max_profit, profit);
                lower--;
            }
        }
        return max_profit;
    }
};
