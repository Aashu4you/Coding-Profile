class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0 ;long long windowSum = 0 , maxSum = 0;
        unordered_map<int,int> freq;
        for(int r=0;r<n;r++){
            windowSum+=arr[r];
            freq[arr[r]]++;
            if(r-l+1>k){
                freq[arr[l]]--;
                windowSum-=arr[l];
                if(freq[arr[l]]==0){
                    freq.erase(arr[l]);
                }
                l++;
            }
            if(r-l+1==k && freq.size()==k){
                maxSum = max(windowSum,maxSum);
            }
        }
        return maxSum;

    }
};