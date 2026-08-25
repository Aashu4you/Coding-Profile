class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char digit = '0'+x;
        if(s[0]==digit){
            return false;
        }
        if(s.find(digit)!=string::npos){
            return true;
        }
        return false;
    }
};