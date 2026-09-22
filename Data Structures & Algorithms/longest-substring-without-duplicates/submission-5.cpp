class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp; //character->freq
        int left=0, right=0;
        int max_len=0;
        while(right < s.size()){
            mp[s[right]]++;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            max_len=max(max_len, right-left+1);
            right++;
        }
        return max_len;
       
    }
};
