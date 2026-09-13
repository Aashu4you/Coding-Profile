class Solution {
public:
    bool hasAlternatingBits(int n) {
        string bin = bitset<32>(n).to_string();
        int pos = bin.find('1');
        bin = bin.substr(pos);
        for(int i=1;i<bin.size();i++){
            if(bin[i]==bin[i-1]){
                return false;
            }
        }
        return true;
    }
};