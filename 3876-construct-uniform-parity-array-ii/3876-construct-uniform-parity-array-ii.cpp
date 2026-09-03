class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]%2==1){
            return true;
        }
        for(int x:nums){
            if(x%2==1){
                return false;
            }
        }
        return true;
    }
};