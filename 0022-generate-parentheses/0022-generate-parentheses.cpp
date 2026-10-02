class Solution {
public:
    void generate(int open, int close, int n, string path, vector<string>& ans) {
        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        }
        if (open < n) {
            generate(open + 1, close, n, path + "(", ans);
        }
        if (close < open) {
            generate(open, close + 1, n, path + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0, 0, n, "", ans);
        return ans;
    }
};