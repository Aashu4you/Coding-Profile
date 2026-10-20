class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prev = 0;

            for (int i = 0; i < n && valid; i += k) {
                int drops = 0;
                int start = i;

                for (int j = i; j < i + k - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        drops++;
                        start = j + 1;
                    }
                }

                if (drops > 1) {
                    valid = false;
                    break;
                }

                if (drops == 1 &&
                    nums[i + k - 1] > nums[i]) {
                    valid = false;
                    break;
                }

                int mn = nums[i], mx = nums[i];

                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }

                if (i > 0 && prev > mn) {
                    valid = false;
                    break;
                }

                prev = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};