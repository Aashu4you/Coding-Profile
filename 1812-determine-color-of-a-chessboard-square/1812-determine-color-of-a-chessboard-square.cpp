class Solution {
public:
    bool squareIsWhite(string coordinates) {
        string c = coordinates;
        int sum=0;
        if(c[0]=='a'||c[0]=='c'||c[0]=='e'||c[0]=='g'){
            sum++;
        }
        if(c[1]=='1'||c[1]=='3'||c[1]=='5'||c[1]=='7'){
            sum++;
        }
        return sum%2!=0;
    }
};