class Solution {
public:
/*
1st step: create a map and store characters from t string into a map. 
We create a variable called as count to know if we have got all the required characters from string t in our window s
2nd step: traverse the window on string s and find min length of the window containing all the characters from string t
NOTE : In map if char freq = 1, it means it is not included in the sliding window (count--), and if the freq < 1, it means the the sliding window has that character inclduded (count++)
*/
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
