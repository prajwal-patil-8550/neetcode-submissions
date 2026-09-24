class Solution {
public:
    string minWindow(string s, string t) {
        int t_size=t.size();
        int left=0, right=0;
        int start_index=-1;
        int min_length=INT_MAX;
        int count = 0;

        unordered_map<char, int>mp;     //character->freq
        for(auto item : t){
            mp[item]++;
        }

        while(right < s.size()){
            if(mp[s[right]] > 0) count++;
            mp[s[right]]--;

            while(count == t_size){
                if(right-left+1 < min_length){
                    min_length=right-left+1;
                    start_index=left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) count--;
                left++;
            }
            right++;
        }
        string ans="";
        if(start_index==-1){
            return ans;
        }
        for(int i=start_index; i<start_index+min_length; i++){
            ans+=s[i];
        }
        return ans;
    }
};
