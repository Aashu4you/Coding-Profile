class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        for(int x:nums){
            if(freq[x]==1 && freq[x-1]==0 && freq[x+1]==0){
                ans.push_back(x);
            }
        }
        return ans;

    }
};