class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp; //char->freq
        int left=0, right=0;
        int max_len=0;
        while(right<s.size()){
           mp[s[right]]++;
           int max_count=0;
           for(auto item : mp){
            max_count=max(max_count, item.second);
           }
           while( (right-left+1) - max_count > k){
            mp[s[left]]--;
            left++;
           }
           max_len=max(max_len, right-left+1);
           right++;    
        }
        return max_len;
    }
};
