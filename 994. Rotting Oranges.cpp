class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutesElapsed = -1;
        int freshOrange = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> queue;
        for(int r = 0; r < ROWS; ++r) {
            for(int c = 0; c < COLS; ++c) {
                if(grid[r][c] == 2) {
                    queue.push(make_pair(r, c));
                } else if(grid[r][c] == 1) {
                    freshOrange++;
                }
            }
        }
        
        queue.push(make_pair(-1, -1));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(queue.size() > 0) {
            auto p = queue.front();
            queue.pop();
            if(p.first == -1) {
                ++minutesElapsed;
                if(queue.size() > 0) {
                    queue.push(make_pair(-1, -1));
                }
            }
            
            for(int i = 0; i < dir.size(); ++i) {
                int newR = p.first + dir[i][0];
                int newC = p.second + dir[i][1];
                if(newR >= 0 && newR < ROWS && newC >=0 
                   && newC < COLS && grid[newR][newC] == 1) {
                    grid[newR][newC] = 2;
                    queue.push(make_pair(newR, newC));
                    freshOrange--;
                }
            }
        }
        
        return freshOrange == 0 ? minutesElapsed : -1;
    }
};
