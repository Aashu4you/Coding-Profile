class Solution {

    int n, k;

    class Node {
        int prod;
        int[] cnt;

        Node() {
            prod = 1;
            cnt = new int[k];
        }
    }

    Node[] tree;

    Node merge(Node left, Node right) {

        Node ans = new Node();
        for (int r = 0; r < k; r++) {
            ans.cnt[r] += left.cnt[r];
        }
        for (int r = 0; r < k; r++) {
            int newRem = (left.prod * r) % k;
            ans.cnt[newRem] += right.cnt[r];
        }
        ans.prod = (left.prod * right.prod) % k;

        return ans;
    }

    void build(int node, int l, int r, int[] nums) {

        if (l == r) {
            int val = nums[l] % k;

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);

        tree[node] = merge(tree[2 * node + 1],
                           tree[2 * node + 2]);
    }

    void update(int node, int l, int r, int index, int value) {

        if (l == r) {

            value %= k;

            tree[node] = new Node();

            tree[node].prod = value;
            tree[node].cnt[value] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            update(2 * node + 1, l, mid, index, value);
        } else {
            update(2 * node + 2, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[2 * node + 1],
                           tree[2 * node + 2]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;
        if (ql > mid) {
            return query(2 * node + 2,
                         mid + 1,
                         r,
                         ql,
                         qr);
        }

        if (qr <= mid) {
            return query(2 * node + 1,
                         l,
                         mid,
                         ql,
                         qr);
        }

        Node left = query(2 * node + 1,
                          l,
                          mid,
                          ql,
                          qr);

        Node right = query(2 * node + 2,
                           mid + 1,
                           r,
                           ql,
                           qr);

        return merge(left, right);
    }

    public int[] resultArray(int[] nums, int k, int[][] queries) {

        this.n = nums.length;
        this.k = k;

        tree = new Node[4 * n];

        for (int i = 0; i < 4 * n; i++) {
            tree[i] = new Node();
        }

        build(0, 0, n - 1, nums);

        int[] ans = new int[queries.length];

        for (int q = 0; q < queries.length; q++) {

            int index = queries[q][0];
            int value = queries[q][1];
            int start = queries[q][2];
            int x = queries[q][3];
            update(0, 0, n - 1, index, value);
            Node res = query(0, 0, n - 1, start, n - 1);

            ans[q] = res.cnt[x];
        }

        return ans;
    }
}