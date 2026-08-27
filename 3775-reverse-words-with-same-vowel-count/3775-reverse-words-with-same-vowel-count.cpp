class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        ss >> word;
        int count = 0;
        for(char ch : word) {
            if(ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u') {
                count++;
            }
        }
        string ans = word;
        while(ss >> word) {
            int tcount = 0;
            for(char ch : word) {
                if(ch == 'a' || ch == 'e' || ch == 'i' ||
                   ch == 'o' || ch == 'u') {
                    tcount++;
                }
            }
            if(count == tcount) {
                int l = 0;
                int r = word.size() - 1;
                while(l<=r) {
                    swap(word[l],word[r]);
                    l++;
                    r--;
                }
            }
            ans+= " " + word;
        }
        return ans;
    }
};