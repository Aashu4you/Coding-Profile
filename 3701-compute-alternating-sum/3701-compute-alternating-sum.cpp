class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int esum = 0 , osum = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                esum+=nums[i];
            }else{
                osum+=nums[i];
            }
        }
        return esum-osum;
    }
};