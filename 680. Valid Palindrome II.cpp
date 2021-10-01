class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) {
                return isValid(s, left + 1, right) || isValid(s, left, right - 1);
            } else {
                left++; right--;
            }
        }
        return true;
    }
    
    bool isValid(string s, int left, int right) {
        while(left < right) {
            if(s[left] == s[right]){
                left++; right--;
            } else {
                return false;
            }
        }
        return true;
    }
};
