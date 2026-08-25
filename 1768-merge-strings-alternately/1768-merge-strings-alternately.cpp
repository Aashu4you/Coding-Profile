class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i=0 , j=0;
        string s = "";
        while(i<n && j<m){
            s = s+word1[i]+word2[j];
            i++;
            j++;
        }
        while(i<n){
            s+=word1[i];
            i++;
        }
        while(j<m){
            s+=word2[j];
            j++;
        }
        return s;
    }
};