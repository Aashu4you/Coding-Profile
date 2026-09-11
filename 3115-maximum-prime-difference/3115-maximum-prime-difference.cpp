class Solution {
public:
    bool isPrime(int n){
        if(n<2){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int left = 0;
        for(int i=0;i<nums.size();i++){
            if(isPrime(nums[i])){
                left=i;
                break;
            }
        }
        int right=left;
        for(int j=left+1;j<nums.size();j++){
            if(isPrime(nums[j])){
                right=j;
            }
        }
        return abs(left-right);
    }
};