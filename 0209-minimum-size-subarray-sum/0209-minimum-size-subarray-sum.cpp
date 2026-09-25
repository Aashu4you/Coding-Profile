class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX , l = 0;
        int sum = 0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                length = min(length,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(length == INT_MAX){
            return 0;
        }else{
            return length;
        }
    }
};