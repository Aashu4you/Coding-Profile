class Solution {
public:
    int findComplement(int n) {
        string bin = bitset<32>(n).to_string();
        int pos = bin.find('1');
        bin = bin.substr(pos);
        string ans = "";
        for(char c:bin){
            if(c=='0'){
                ans+="1";
            }else{
                ans+="0";
            }
        }
        int num = stoi(ans,nullptr,2);
        return num;
    }
};