class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product = 1 , ans = 0;
        int l = 0;
        if(k<=1) return 0;
        for(int r=0;r<n;r++){
            product*=nums[r];
            while(product>=k){
                product /=nums[l];
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};