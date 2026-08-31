class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> freq(26,false);
        int ans=0;
        for(char ch:allowed){
            freq[ch-'a']=true;
        }
        for(string word:words){
            bool what = true;
            for(char ch:word){
                if(!freq[ch-'a']){
                    what=false;
                    break;
                }
            }
            if(what){
                ans++;
            }
        }
        return ans;

    }
};