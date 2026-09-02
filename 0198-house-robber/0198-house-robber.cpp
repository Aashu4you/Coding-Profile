class Solution {
public:

    int maxloot(vector<int>&arr,int idx,vector<int>&dp){
        if(idx>=arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int steal = arr[idx]+maxloot(arr,idx+2,dp);
        int skip = maxloot(arr,idx+1,dp);
        return dp[idx]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans = maxloot(nums,0,dp);
        return ans;
    }
};