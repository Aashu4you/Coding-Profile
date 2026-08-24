class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n)+to_string(2*n)+to_string(n*3);
        if(s.size()!=9){
            return false;
        }
        vector<int> freq(10,0);
        for(char c:s){
            freq[c-'0']++;
        }
        for(int i=1;i<=9;i++){
            if(freq[i]!=1){
                return false;
            }
        }
        return true;
    }
};