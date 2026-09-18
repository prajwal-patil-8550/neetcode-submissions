class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0; i<strs.size(); i++){
            string sorted=strs[i];
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(strs[i]);
        }
        for(auto item : mp){
            ans.push_back(item.second);
        }
        return ans;
    }
};
