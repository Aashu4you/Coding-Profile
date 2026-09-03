class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        int maxfreq=0;
        for(auto it:freq){
            if(it.second>maxfreq){
                maxfreq=it.second;
            }
        }
        int ans=0;
        for(auto it:freq){
            if(it.second==maxfreq){
                ans+=maxfreq;
            }
        }
        return ans;
    }
};