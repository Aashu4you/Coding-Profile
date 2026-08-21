class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Count distinct amounts <= x
        auto count = [&](long long x) {
            long long total = 0;

            // Inclusion-exclusion over all subsets
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool overflow = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = std::gcd(lcm, (long long)coins[i]);

                        // lcm(a,b) = a/gcd(a,b) * b
                        lcm = (lcm / g) * coins[i];

                        if (lcm > x) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow)
                    continue;

                if (bits % 2 == 1)
                    total += x / lcm;
                else
                    total -= x / lcm;
            }

            return total;
        };

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};