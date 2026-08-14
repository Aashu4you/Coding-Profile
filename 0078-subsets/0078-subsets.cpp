class Solution {
public:
    void generate(vector<int>& nums, int index,
                  vector<int>& curr,
                  vector<vector<int>>& ans) {
        if(index == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        generate(nums, index + 1, curr, ans);
        curr.pop_back();
        generate(nums, index + 1, curr, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        generate(nums, 0, curr, ans);
        return ans;
    }
};