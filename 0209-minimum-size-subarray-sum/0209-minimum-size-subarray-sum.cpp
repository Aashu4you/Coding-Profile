class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int length = INT_MAX , l = 0 , sum =0;
        for(int r=0;r<n;r++){
            sum+= nums[r];
            while(sum>=target){
                length= min(length,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(length==INT_MAX){
            return 0;
        }else{
            return length;
        }
    }
};