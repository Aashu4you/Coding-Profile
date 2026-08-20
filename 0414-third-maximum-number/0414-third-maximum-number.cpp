class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int k = 1;int i=n-1;
        while(i>=1){
            if(nums[i]!=nums[i-1]){
                k++;
                if(k==3){
                    return nums[i-1];
                }
            }
            i--;
        }
        return nums[n-1];
    }
};