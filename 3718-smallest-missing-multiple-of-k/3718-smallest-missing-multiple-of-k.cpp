class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> present;
        for(int x:nums){
            present.insert(x);
        }
        int multiple = k;
        while(present.count(multiple)){
            multiple+=k;
        }
        return multiple;
    }
};