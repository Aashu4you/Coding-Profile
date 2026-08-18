class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int x : stones) {
            if (x % 3 == 0)
                cnt0++;
            else if (x % 3 == 1)
                cnt1++;
            else
                cnt2++;
        }

        // If number of 0-mod-3 stones is even
        if (cnt0 % 2 == 0) {
            return cnt1 > 0 && cnt2 > 0;
        }

        // If number of 0-mod-3 stones is odd
        return abs(cnt1 - cnt2) > 2;
    }
};