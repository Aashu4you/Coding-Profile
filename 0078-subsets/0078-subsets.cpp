class Solution {
public:
    void solve(vector<int> &nums, int idx , vector<int> &temp , vector<vector<int>>&ans ){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums,idx+1,temp,ans);
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp,ans);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,temp,ans);
        return ans;
    }
};