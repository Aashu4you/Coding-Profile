class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int curmax = 0 , curmin = 0 ;
        int maxsum = nums[0] ,minsum = nums[0];
        for(int x:nums){
            curmax = max(x,curmax+x);
            maxsum = max(maxsum , curmax);

            curmin = min(x,curmin+x);
            minsum = min(minsum,curmin);
        }
        return max(maxsum,abs(minsum));
    }
};