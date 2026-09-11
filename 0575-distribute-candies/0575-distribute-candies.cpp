class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;
        for(int x:candyType){
            st.insert(x);
        }
        int m = st.size();
        if(m<=n/2){
            return m;
        }else{
            return n/2;
        }
    }
};