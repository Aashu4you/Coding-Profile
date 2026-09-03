class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26]={};
        bool upper[26]={};
        int ans=0;
        for(char c:word){
            if(c>='a' && c<='z'){
                lower[c-'a']=true;
            }else{
                upper[c-'A']=true;
            }
        }
        for(int i=0;i<26;i++){
            if(lower[i] && upper[i]){
                ans++;
            }
        }
        return ans;
    }
};