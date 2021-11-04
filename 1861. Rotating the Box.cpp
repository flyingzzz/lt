class Solution {
public:
    //done by self
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size(); 
        int cols = box[0].size();
        vector<vector<char>> ans(cols, vector<char>(rows));
        for(int r = 0; r < rows; ++r) {
            int lastEmpty = -1;
            for(int c = cols - 1; c >=0; --c) {
                if(box[r][c] == '*') {
                    lastEmpty = -1;
                    ans[c][rows - r - 1] = '*';
                } else if(box[r][c] == '.') {
                    if(lastEmpty == -1) {
                        lastEmpty = c;
                    }
                    ans[c][rows - r - 1] = '.';
                }else if(box[r][c] == '#') {
                    if(lastEmpty >= 0) {
                        ans[lastEmpty][rows - r - 1] = '#';
                        ans[c][rows - r - 1] = '.';
                        lastEmpty -= 1;
                    } else {
                        ans[c][rows - r - 1] = '#';
                    }
                }
            }
        }
        
        return ans;
    }
};
