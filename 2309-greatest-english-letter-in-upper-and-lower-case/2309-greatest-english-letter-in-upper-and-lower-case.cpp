class Solution {
public:
    string greatestLetter(string s) {
        bool upper[26]={};
        bool lower[26]={};
        for(char ch:s){
            if(ch>='a' && ch<='z'){
                lower[ch-'a']= true;
            }else{
                upper[ch-'A']=true;
            }
        }
        string ans="";
        //ulta chalega kyuki we want the greatest not the smallest
        for(int i=25;i>=0;i--){
            if(lower[i] && upper[i]){
                ans+=char('A'+i);
                return ans;
            }
        }
        return ans;

    }
};