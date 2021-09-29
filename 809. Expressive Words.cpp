class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0; 
        int m = s.size();
        for(string word : words) {
            int i = 0; int j = 0;
            for(i = 0; i < m; ++i) {
                if(j < word.size() && s[i] == word[j]) ++j;
                else if( i > 0 && s[i] == s[i - 1] && i + 1 < m && s[i] == s[i + 1]) ++i;
                //case: aa, a
                else if(! (i > 1 && s[i] == s[i - 1] && s[i] == s[i - 2])) break;
            }
            
            if(i == m && j == word.size()) ++ res;
        }
        
        return res;
    }
};
