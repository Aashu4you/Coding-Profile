class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        int first = freq.begin()->second;
        for(auto it:freq){
            if(it.second!=first){
                return false;
            }
            first=it.second;
        }
        return true;
    }
};