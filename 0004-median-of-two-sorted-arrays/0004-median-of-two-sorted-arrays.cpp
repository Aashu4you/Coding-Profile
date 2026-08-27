class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int x:nums1){
            ans.push_back(x);
        }
        for(int x:nums2){
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        double median = 0;
        int n = ans.size();
        if(n%2==0){
            int m = n/2;
            median = (ans[m-1]+ans[m])/2.0;
        }else{
            int m = n/2;
            median=ans[m]; 
        }
        return median;
    }
};