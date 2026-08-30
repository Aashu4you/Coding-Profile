class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxiPos = 0 , miniPos=0;
        int maxi = nums[0] , mini = nums[0];
        for(int x:nums){
            if(x>maxi){
                maxi=x;
            }
        }
        for(int x:nums){
            if(x<mini){
                mini=x;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                maxiPos=i;
            }
            if(nums[i]==mini){
                miniPos=i;
            }
        }
        int left = min(maxiPos,miniPos);
        int right = max(maxiPos,miniPos);
        int fromFront = right+1;
        int fromBack = n-left;
        int fromBoth = (left+1)+(n-right);
        return min({fromFront,fromBack,fromBoth});
    }
};