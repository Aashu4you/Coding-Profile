class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(char c:word){
            if(c>='A' && c<='Z'){
                cap++;
            }
        }
        if(cap==word.size()) return true;
        if(cap==0) return true;
        if(cap==1 && word[0]>='A'&& word[0]<='Z') return true;
        return false;
    }
};