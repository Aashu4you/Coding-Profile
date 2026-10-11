class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        priority_queue<pair<int,int>> maxheap;

        for(auto it:freq){
            maxheap.push({it.second,it.first});
        }
        vector<int> result;

        while(k--){
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return result;
    }
};