class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> map1;
        unordered_map<string,int> map2;
        string word;
        vector<string> ans;
        stringstream ss1(s1);
        while(ss1>>word){
            map1[word]++;
        }
        stringstream ss2(s2);
        while(ss2>>word){
            map2[word]++;
        }
        for(auto it:map1){
            if(it.second==1 && map2.find(it.first)==map2.end()){
                ans.push_back(it.first);
            }
        }
        for(auto it:map2){
            if(it.second==1 && map1.find(it.first)==map1.end()){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};