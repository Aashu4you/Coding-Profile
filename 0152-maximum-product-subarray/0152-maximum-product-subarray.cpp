class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxprod = arr[0] , minprod = arr[0] , ans = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<0){
                swap(minprod,maxprod);
            }
            maxprod = max(arr[i],maxprod*arr[i]);
            minprod = min(arr[i],minprod*arr[i]);
            ans=max(maxprod,ans);
        }
        return ans;
    }
};