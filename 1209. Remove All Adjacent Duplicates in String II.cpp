class Solution {
public:
    string removeDuplicates(string s, int k) {
        //deeedbbcccbdaa
        //count first: 1 1 2 3
        //count second:1 2 1 2 1 2 3
        //count third: 1 2 1 2 3
        //count fouth: 1 2 3
        //count five: 1 2, return
        vector<int> count(s.size(), 0);
        for(int i = 0; i < s.size(); ++i) {
            if(i == 0 || s[i] != s[i-1]) {
                count[i] = 1;
            } else {
                count[i] = count[i - 1] + 1;
                if(count[i] == k) {
                    s.erase(i - k + 1, k);
                    i = i - k;
                }
            }
        }
        return s;
    }
};
