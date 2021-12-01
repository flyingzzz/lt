class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        if(n <= 1)
            return s;
        string res(s.substr(0,1));
        for(int i = 1; i < n; ++i) {
            if(res.size() > 0 && res.back() == s[i]) {
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
