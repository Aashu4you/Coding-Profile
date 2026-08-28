class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(s==goal){
                return true;
            }
            char ch = s[0];
            s.erase(s.begin());
            s+=ch;
        }
        return false;
    }
};