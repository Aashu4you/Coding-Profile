
class Solution {
public:
    static const long long MOD = 1e9 + 7;

    struct SegmentTree {
        int n;
        vector<long long> sum, sq, lazy;

        SegmentTree(int n) : n(n), sum(4 * n), sq(4 * n), lazy(4 * n) {}

        void apply(int node, int left, int right, long long val) {
            long long len = right - left + 1;
            sq[node] = (sq[node] + 2 * val % MOD * sum[node] % MOD
                      + len % MOD * val % MOD * val) % MOD;
            sum[node] = (sum[node] + len * val) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
        }

        void push(int node, int left, int right) {
            if (lazy[node] == 0 || left == right) return;
            int mid = (left + right) / 2;
            apply(node * 2, left, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, right, lazy[node]);
            lazy[node] = 0;
        }

        void update(int node, int left, int right, int ql, int qr) {
            if (ql > right || qr < left) return;
            if (ql <= left && right <= qr) {
                apply(node, left, right, 1);
                return;
            }

            push(node, left, right);
            int mid = (left + right) / 2;
            update(node * 2, left, mid, ql, qr);
            update(node * 2 + 1, mid + 1, right, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        }

        long long query(int node, int left, int right, int ql, int qr) {
            if (ql > right || qr < left) return 0;
            if (ql <= left && right <= qr) return sq[node];

            push(node, left, right);
            int mid = (left + right) / 2;

            return (query(node * 2, left, mid, ql, qr)
                  + query(node * 2 + 1, mid + 1, right, ql, qr)) % MOD;
        }

        void update(int l, int r) {
            update(1, 0, n - 1, l, r);
        }

        long long query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    };

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);
        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            st.update(last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + st.query(0, i)) % MOD;
        }

        return ans;
    }
};
