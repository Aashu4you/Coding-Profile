class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {

                if (op == '+')
                    st.push(num);
                else if (op == '-')
                    st.push(-num);
                else if (op == '*') {
                    int x = st.top();
                    st.pop();
                    st.push(x * num);
                }
                else if (op == '/') {
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};