class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }else{
                int operand2=st.top();
                st.pop();
                int operand1=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(operand1+operand2);
                }else if(tokens[i]=="-"){
                    st.push(operand1-operand2);
                }else if(tokens[i]=="*"){
                    st.push(operand1*operand2);
                }else{
                    st.push(operand1/operand2);
                }
            }
        }
        return st.top();
    }
};
