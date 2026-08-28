class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN , slargest = INT_MIN;
        for(int x:nums){
            if(x>largest){
                slargest=largest;
                largest=x;
            }else if(x>slargest && x<largest){
                slargest=x;
            }
        }
        bool what = false;
        if(largest>=2*slargest){
            what=true;
        }
        if(what){
            for(int i = 0;i<nums.size();i++){
                if(nums[i]==largest){
                    return i;
                }
            }
        }
        return -1;
    }
};