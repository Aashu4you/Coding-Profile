class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word;
        string ans="";
        int count =0;
        for(int i=0;i<k;i++){
            ss>>word;
            if(i>0){
                ans+=" ";
            }
            ans+=word;
        }
        return ans;
    }
};