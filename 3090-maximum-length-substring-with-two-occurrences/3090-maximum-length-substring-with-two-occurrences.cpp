class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0 , ans=0;
        unordered_map<char,int> freq;
        for(int r=0;r<n;r++){
            freq[s[r]]++;
            while(freq[s[r]]>2){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};