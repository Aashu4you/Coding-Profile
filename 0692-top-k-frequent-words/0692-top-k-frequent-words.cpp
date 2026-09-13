class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        vector<string> temp;
        for(string x:words){
            freq[x]++;
        }
        for(auto it:freq){
            temp.push_back(it.first);
        }
        sort(temp.begin(),temp.end(),[&](string a,string b){
            if(freq[a]!=freq[b]){
                return freq[a]>freq[b];
            }
            return a<b;
        });
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};