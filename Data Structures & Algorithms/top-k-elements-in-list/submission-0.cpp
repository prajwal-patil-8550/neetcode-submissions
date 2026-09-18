class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp1;  // num->freq
        for(auto num:nums){
            mp1[num]++;
        }
        /* mistake: i created another map to store freq->num but there could be a case like {1, 1, 2, 2, 3} here mp1 becomes [1->2, 2->2, 3->1] and i was tryna do mp2 like [2->1, 2->2, 1->3] BUT BUT a map can have only one key with unique value so there cant be two keys of 2 so 1st one gets overriden by second and mp2 becomes [2->2, 1->3].
        
        i can rather solve it by using only 1 map and store it into heap later*/
        priority_queue<pair<int, int>>pq;
        for(auto item : mp1){
            pq.push({item.second, item.first});
        }
        vector<int> ans;
        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
