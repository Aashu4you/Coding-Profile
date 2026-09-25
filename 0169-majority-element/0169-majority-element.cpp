class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int maxi = 0;
        int maxfreq=0;
        for(auto it: freq){
            if(it.second>maxfreq){
                maxfreq = it.second;
                maxi=it.first;
            }
        }
        return maxi;
    }
};