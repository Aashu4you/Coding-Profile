class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int x:nums){
            ans.push_back(x);
        }
        for(int x:nums){
            string s = to_string(x);
            reverse(s.begin(),s.end());
            int y = stoi(s);
            ans.push_back(y);
        }
        unordered_set<int> st;
        int count=0;
        for(int x:ans){
            if(!st.count(x)){
                st.insert(x);
                count++;
            }
        }
        return count;
    }
};