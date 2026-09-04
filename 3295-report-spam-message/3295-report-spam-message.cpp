class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count=0;
        unordered_set<string> banned(bannedWords.begin(),bannedWords.end());
        for(string s:message){
            if(banned.count(s)){
                count++;
            }
            if(count==2){
                return true;
            }
        }
        return false;
    }
};