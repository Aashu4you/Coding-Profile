class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_set<char> st;
        for(char c:jewels){
            st.insert(c);
        }
        for(char c:stones){
            if(st.count(c)){
                ans++;
            }
        }
        return ans;
    }
};