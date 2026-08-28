class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int esum = 0 , dsum = 0;
        for(int x:nums){
            esum+=x;
            while(x>0){
                dsum+=x%10;
                x/=10;
            }
        }
        return abs(dsum-esum);
    }
};