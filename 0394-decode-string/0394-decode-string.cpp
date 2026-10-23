
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string curr= "";
        int num= 0;
        for (char c:s) {
            if(isdigit(c)) {
                num= num*10 + (c -'0');
            }
            else if(c=='[') {
                st.push(curr);
                st.push(to_string(num));
                curr = "";
                num = 0;
            }
            else if(c==']') {
                int k =stoi(st.top());
                st.pop();
                string prev =st.top();
                st.pop();
                string temp ="";
                for (int i = 0;i<k;i++) {
                    temp +=curr;
                }

                curr=prev+temp;
            }
            else{
                curr +=c;
            }
        }
        return curr;
    }
};
