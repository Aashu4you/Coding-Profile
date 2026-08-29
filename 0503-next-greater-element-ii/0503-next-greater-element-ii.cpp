class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int x:nums){
            temp.push_back(x);
        }
        for(int x:nums){
            temp.push_back(x);
        }
        int m = temp.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            while(st.size()>0 && st.top()<=temp[i]){
                st.pop();
            }
            if(i<n){
                if(st.empty()){
                    ans[i]=-1;
                }else{
                    ans[i]=st.top();
                }
            }
            st.push(temp[i]);
        }
        return ans;
    }
};