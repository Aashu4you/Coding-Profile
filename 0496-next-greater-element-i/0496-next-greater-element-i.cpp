class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> map;
        for(int x:nums2){
            while(!st.empty() && x>st.top()){
                map[st.top()]=x;
                st.pop();
            }
            st.push(x);
        }
        vector<int> ans;
        for(int num:nums1){
            if(map.count(num)){
                ans.push_back(map[num]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};