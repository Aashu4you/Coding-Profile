class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans="";
        while(ss>>word){
            int l = 0 , r = word.size()-1;
            while(l<=r){
                swap(word[l],word[r]);
                l++;
                r--;
            }
            if(ans!=""){
                ans+=" ";
            }
            ans+=word;
        }
        return ans;
    }
};