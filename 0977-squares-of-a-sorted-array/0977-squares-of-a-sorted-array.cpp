class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int x:nums){
            int num = x*x;
            ans.push_back(num);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};