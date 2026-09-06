class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = values.size();
        long long score=0;
        int i=0;
        vector<int> mark(n,0);
        while(i>=0 && i<n){
            mark[i]++;
            if(mark[i]==2){
                break;
            }else{
                if(instructions[i]=="add"){
                    score+=values[i];
                    i++;
                }else{
                    i= i+values[i];
                }
            }
            
        }
        return score;
    }
};