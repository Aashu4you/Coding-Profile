class Solution {
public: 
    int solvethis(int n , vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solvethis(n-1,dp)+solvethis(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = solvethis(n,dp);
        return ans;
    }
};