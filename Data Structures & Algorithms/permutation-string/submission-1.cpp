class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>window(26, 0);
        vector<int>s1Freq(26, 0);

        for(int i=0; i<s1.size(); i++){
            s1Freq[s1[i]-'a']++;
        }

        int left=0, right=0;
        while(right < s2.size()){
            window[s2[right]-'a']++;
            // int windowSize=right-left+1; cuz of initializing variable here in the nested if condition inside the else if condition the updated window size was not being calculated

           
            if(right-left+1 > s1.size()){
                window[s2[left]-'a']--;
                left++;
            }
            if(right-left+1 == s1.size() && s1Freq == window){
                return true;
            }
            right++;
        }
        return false;
    }
};
