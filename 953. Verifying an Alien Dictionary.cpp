class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int orderMap[26] = {0};
        for(int i = 0; i < order.size(); ++i) {
            orderMap[order[i] - 'a'] = i;
        }
        for(int i = 0; i < words.size() - 1; ++i) {
            for(int j = 0; j < words[i].size(); ++j) {
                if(j >= words[i+1].size()) return false;
                if(words[i][j] != words[i+1][j]) {
                    int currentChar = words[i][j] - 'a';
                    int nextChar = words[i+1][j] - 'a';
                    if(orderMap[currentChar] > orderMap[nextChar]) return false;
                    break;
                }
            }
        }
        return true;
    }
};
