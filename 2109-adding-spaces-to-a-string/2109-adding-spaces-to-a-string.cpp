class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size();
        int l=0;
        for(int i=0;i<n;i++){
            if(l<spaces.size() && i==spaces[l]){
                ans+=" ";
                l++;
            }
            ans+=s[i];
        }
        return ans;
    }
};