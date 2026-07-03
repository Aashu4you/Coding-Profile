class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int l = 0 , maxArea = 0 , r = n-1;
        while(l<r){
            int height = min(arr[l],arr[r]);
            int width = r-l;
            int area = height*width;
            maxArea = max(maxArea,area);
            if(arr[l]<arr[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};