class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0] , maxsum = nums[0];
        for(int i=1;i<n;i++){
            sum = max(nums[i],sum+nums[i]);
            maxsum = max(sum,maxsum);
        }
        return maxsum;
    }
};