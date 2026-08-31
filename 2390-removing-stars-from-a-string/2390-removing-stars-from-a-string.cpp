class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        string ans="";
        for(char c:s){
            if(c!='*'){
                st.push(c);
            }else if(c=='*'){
                st.pop();
            }

        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};