class Solution {
public:
    int maxloot(vector<int>&nums,int idx,int end,vector<int>&dp){
        if(idx>end) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int steal = nums[idx]+maxloot(nums,idx+2,end,dp);
        int skip = maxloot(nums,idx+1,end,dp);
        return dp[idx] = max(skip,steal);
    }
    int rob(vector<int>& nums) { 
       int n = nums.size();
       if(n==1){
            return nums[0];
       }
       vector<int> dp1(nums.size(),-1);
       vector<int> dp2(nums.size(),-1);
       int fromBeg = maxloot(nums,0,n-2,dp1);
       int fromEnd = maxloot(nums,1,n-1,dp2);
       int ans = max(fromBeg,fromEnd);
       return ans;
    }
};