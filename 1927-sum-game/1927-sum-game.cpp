class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int diff = 0;
        int leftQ = 0;
        int rightQ = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        for(int i = n / 2; i < n; i++) {
            if(num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }

        int qDiff = leftQ - rightQ;

        if(qDiff % 2 != 0)
            return true;

        return diff != -9 * qDiff / 2;
    }
};