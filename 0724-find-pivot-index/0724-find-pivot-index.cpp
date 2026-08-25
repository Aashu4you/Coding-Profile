class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftsum = 0 , totalsum = 0;
        for(int x:nums){
            totalsum+=x;
        }
        for(int i=0;i<n;i++){
            int rightsum = totalsum-leftsum-nums[i];
            if(leftsum==rightsum){
                return i;
            }
            leftsum +=nums[i];
        }
        return -1;
    }
};