class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1 , high = num;
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(mid*mid==num){
                ans=mid;
                break;
            }else if(mid*mid<num){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans != -1;
    }
};