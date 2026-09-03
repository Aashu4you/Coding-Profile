class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        vector<int> temp;
        for(auto it:freq){
            if(it.second==2){
                temp.push_back(it.first);
            }
        }
        int xorr=0;
        for(int x:temp){
            xorr=xorr^x;
        }
        return xorr;
    }
};