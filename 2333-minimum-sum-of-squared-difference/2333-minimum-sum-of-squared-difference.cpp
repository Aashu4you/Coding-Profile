
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> freq(100001, 0);
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
        }

        if (total <= k) return 0;

        for (int d = 100000; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long count = freq[d];
            long long operations = min(k, count);

            freq[d] -= operations;
            freq[d - 1] += operations;
            k -= operations;
        }

        long long answer = 0;

        for (int d = 1; d <= 100000; d++) {
            answer += freq[d] * d * d;
        }

        return answer;
    }
};