class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int left=0;left<n;left++){
            unordered_set<int> st;
            for(int right=left;right<n;right++){
                st.insert(nums[right]);
                int count = st.size();
                ans+= count*count;
            }
        }
        return ans;
    }
};