class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                //edge case where closing brackets > opening brackets
                if(st.size() == 0)  return false;
                if(st.top()=='(' && s[i]==')' ||
                   st.top()=='{' && s[i]=='}' ||
                   st.top()=='[' && s[i]==']'){

                    //if opening bracket matches closing bracket continue
                    st.pop();
                }else{
                    //else it doesnt match
                    return false;
                }   
            }
        }
        return st.size()==0;  //edge case where opening bracket > closing bracket
    }
};
