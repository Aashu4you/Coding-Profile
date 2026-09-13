class Solution {
public:
    int hammingWeight(int n) {
        string bin = bitset<32>(n).to_string();
        int count=0;
        for(char c:bin){
            if(c=='1'){
                count++;
            }
        }
        return count;
    }
};