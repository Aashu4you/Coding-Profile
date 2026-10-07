class Solution {
public:
    vector<string> ans;
    
    void solve(string &s, int index, int left, int right, int leftRemove, int rightRemove, string curr) {
        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && left == right) {
                ans.push_back(curr);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            if (leftRemove > 0) {
                solve(s, index + 1, left, right, leftRemove - 1, rightRemove, curr);
            }

            solve(s, index + 1, left + 1, right, leftRemove, rightRemove, curr + c);
        }
        else if (c == ')') {
            if (rightRemove > 0) {
                solve(s, index + 1, left, right, leftRemove, rightRemove - 1, curr);
            }

            if (left > right) {
                solve(s, index + 1, left, right + 1, leftRemove, rightRemove, curr + c);
            }
        }
        else {
            solve(s, index + 1, left, right, leftRemove, rightRemove, curr + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0, rightRemove = 0;

        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        solve(s, 0, 0, 0, leftRemove, rightRemove, "");

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};