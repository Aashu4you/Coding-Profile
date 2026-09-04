class Solution {
public:
    int fibo(int n , vector<int>&dp){
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fibo(n-1,dp)+fibo(n-2,dp)+fibo(n-3,dp);
    }
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        vector<int> dp(n+1,-1);
        dp[0]=0 , dp[1]=1 , dp[2]=1;
        int ans = fibo(n,dp);
        return ans;
    }
};