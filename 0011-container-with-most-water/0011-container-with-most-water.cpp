class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;int right=height.size()-1;
        int ans = 0;
        while(left<right){
            int width = right-left;
            int hgt = min(height[left],height[right]);
            int area = width*hgt;
            ans = max(area,ans);
            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return ans;
    }
};