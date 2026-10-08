class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.size();
        string ans;
        for(char c:s){
            if(c=='('){
                if(!st.empty()){
                    ans+=c;
                }
                st.push(c);
            }else{
                st.pop();
                if(!st.empty()){
                    ans+=c;
                }
            }
        }
        return ans;
    }
};