class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0 , zeroCnt = 0 , l = 0;
        for(int r=0;r<n;r++){
            if(arr[r]==0) zeroCnt++;
            while(zeroCnt>k){
                if(arr[l]==0){
                    zeroCnt--;
                }
                l++;
            }
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};