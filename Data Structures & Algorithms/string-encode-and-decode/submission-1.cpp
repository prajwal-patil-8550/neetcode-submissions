class Solution {
public:
  

    string encode(vector<string>& strs) {
        string result="";
        for(auto str : strs){
            result+= to_string(str.size()) +="#" + str;
        }
        return result;
    }

    vector<string> decode(string s) { 
        int i=0, j; //iterator for while loop
        vector<string>ans;
        while(i < s.size()){
            j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi( s.substr(i, j-i) );
            ans.push_back(s.substr(j+1, length));
            i=j+1+length;
        }
        return ans;
    }
};
