class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;int maxans=-1;
        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=0;j<n;j++){
                if(nums[j]==(-num)){
                    ans=num;
                    if(ans>maxans){
                        maxans=ans;
                    }
                }
            }
        }
        return maxans;
    }
};