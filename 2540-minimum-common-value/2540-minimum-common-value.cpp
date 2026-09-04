class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        for(int x:nums1){
            map[x]++;
        }
        for(int x:nums2){
            if(map.find(x)!=map.end()){
                return x;
            }
        }
        return -1;
    }
};