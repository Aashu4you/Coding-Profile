class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int n = s.size();

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // We cannot use target[i]
            if (freq[x] == 0) {

                // First, try a character greater than target[i]
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = target.substr(0, i);
                        ans += char('a' + c);
                        freq[c]--;

                        // Put remaining characters in sorted order
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }

                // No larger character here.
                // Backtrack to an earlier position.
                for (int j = i - 1; j >= 0; j--) {

                    // Restore the character used at position j
                    freq[target[j] - 'a']++;

                    int y = target[j] - 'a';

                    // Try a slightly larger character
                    for (int c = y + 1; c < 26; c++) {

                        if (freq[c] > 0) {

                            string ans = target.substr(0, j);
                            ans += char('a' + c);
                            freq[c]--;

                            // Remaining characters sorted
                            for (int k = 0; k < 26; k++) {
                                while (freq[k] > 0) {
                                    ans += char('a' + k);
                                    freq[k]--;
                                }
                            }

                            return ans;
                        }
                    }
                }

                return "";
            }

            // Match target[i]
            freq[x]--;
        }

        // s can form target exactly.
        // Need to find the next greater permutation.
        for (int j = n - 1; j >= 0; j--) {

            // Restore target[j]
            freq[target[j] - 'a']++;

            int x = target[j] - 'a';

            // Find smallest character greater than target[j]
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = target.substr(0, j);
                    ans += char('a' + c);
                    freq[c]--;

                    // Add remaining characters sorted
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};