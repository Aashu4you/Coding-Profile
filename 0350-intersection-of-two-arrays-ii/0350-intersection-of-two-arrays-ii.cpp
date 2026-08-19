class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            map[nums1[i]]++;
        }
        for(int x: nums2){
            if(map[x]>0){
                ans.push_back(x);
                map[x]--;
            }
        }
        return ans;
    }
};