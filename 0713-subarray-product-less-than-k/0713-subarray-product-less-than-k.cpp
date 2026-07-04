class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long product = 1 , count = 0 , l = 0;
        if(k<=1) return 0;
        for(int r=0;r<n;r++){
            product*=nums[r];
            while(product>=k){
                product /= nums[l];
                l++;
            }
            count += (r-l+1);
        }
        return count;
    }
};