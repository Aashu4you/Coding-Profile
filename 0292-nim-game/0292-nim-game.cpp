class Solution {
public:
    bool canWinNim(int n) {
        //whenever n is a multiple of 4 , we will lose the game?? why??
        //because whatever the fk we choose , hes got a complement of that number and we will be defeated
        return n%4!=0;
    }
};