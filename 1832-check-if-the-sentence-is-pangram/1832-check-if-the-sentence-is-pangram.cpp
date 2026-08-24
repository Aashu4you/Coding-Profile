class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> freq;
        for(char ch:sentence){
            freq[ch]++;
        }
        return freq.size()==26;
    }
};