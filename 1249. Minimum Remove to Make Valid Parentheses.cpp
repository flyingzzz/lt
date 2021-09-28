class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int open = 0;
        int close = count(s.begin(), s.end(), ')');
        for(char c : s) {
            if (c == '(') {
                if(open == close) continue;
                open++;
            } else if(c == ')') {
                --close;
                if(open == 0) continue;
                --open;
            }
            res += c;
        }
        
        return res;
    }
};
