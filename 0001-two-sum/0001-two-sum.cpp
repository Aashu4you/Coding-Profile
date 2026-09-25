class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int need = target - a;
            if(map.find(need)!=map.end()){
                return {i,map[need]};
            }
            map[a]=i;
        }
        return {-1,-1};
    }
};