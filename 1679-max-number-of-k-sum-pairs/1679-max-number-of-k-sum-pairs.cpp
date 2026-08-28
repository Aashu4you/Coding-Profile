class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int left=0,right=nums.size()-1;
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum==k){
                ans++;
                left++;
                right--;
            }else if(sum<k){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};