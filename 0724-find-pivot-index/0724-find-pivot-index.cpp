class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        long long leftsum = 0 , totalsum = 0;
        for(int x:nums) totalsum += x;
        for(int i=0;i<n;i++){
            long long rightsum = totalsum - leftsum - nums[i];
            if(rightsum==leftsum) return i;
            leftsum += nums[i];
        }
        return -1;
    }
};