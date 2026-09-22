class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char, int>mp; //character->freq
        // int left=0, right=0;
        // int max_len=0;
        // while(right < s.size()){
        //     mp[s[right]]++;
        //     while(mp[s[right]] > 1){
        //         mp[s[left]]--;
        //         left++;
        //     }
        //     max_len=max(max_len, right-left+1);
        //     right++;
        // }
        // return max_len;
        int left=0, right=0, maxLen=0;
        unordered_set<char>st;
        while(right<s.size()){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen=max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};
