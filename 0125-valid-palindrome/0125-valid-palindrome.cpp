class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 , right = s.size()-1;
        while(left<right){
            //skip the non alphanumeric characters
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;

            //check for palindrome
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};