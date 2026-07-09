class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26,0) , freqS(26,0);
        int k = p.size();
        int n = s.size();

        for(char c : p){
            freqP[c-'a']++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            freqS[s[i]-'a']++;
            if(i>=k){
                freqS[s[i-k]-'a']--;
            }
            if(freqS==freqP){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};