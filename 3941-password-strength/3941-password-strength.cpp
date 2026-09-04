class Solution {
public:
    int passwordStrength(string password) {
        int strength=0;
        int freqa[26]={};
        int freqA[26]={};
        int freq0[10]={};
        int freqS[4]={};
        for(char c:password){
            if(c>='a'&&c<='z'){
                freqa[c-'a']++;
            }else if(c>='A'&&c<='Z'){
                freqA[c-'A']++;
            }else if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'){
                freq0[c-'0']++;
            }else{
                if(c=='!'){
                    freqS[0]++;
                }else if(c=='@'){
                    freqS[1]++;
                }else if(c=='#'){
                    freqS[2]++;
                }else{
                    freqS[3]++;
                }
            }
        }
        int ls = 0 , us = 0 , ds = 0 , ss = 0;
        for(int x: freqa){
            if(x!=0){
                ls++;
            }
        }
        for(int x:freqA){
            if(x!=0){
                us++;
            }
        }
        for(int x:freq0){
            if(x!=0){
                ds++;
            }
        }
        for(int x:freqS){
            if(x!=0){
                ss++;
            }
        }
        us=us*2;
        ds=ds*3;
        ss=ss*5;
        strength = ls+us+ds+ss;
        return strength;
    }
};