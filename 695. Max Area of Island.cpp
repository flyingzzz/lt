class Solution {
public:
    int area(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& seen) {
        int rSize = grid.size();
        int cSize = grid[0].size();
        if(r < 0 || c < 0 || r >= rSize || c >= cSize || 
            grid[r][c] == 0 || seen[r][c] == 1) {
            return 0;
        } else {
            seen[r][c] = 1;
            return 1 + area(r + 1, c, grid, seen) + area(r, c + 1, grid, seen) 
                           + area(r - 1, c, grid, seen) + area(r, c -1, grid, seen);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        int rSize = grid.size();
        int cSize = grid[0].size();
        vector<vector<int>> seen(rSize, vector<int>(cSize, 0));
        
        for(int r = 0; r < rSize; ++r) {
            for(int c = 0; c < cSize; ++c) {
                //pay attention the order of r and c, otherwise crash
                if(grid[r][c] == 1 && seen[r][c] == 0) {
                    int res = area(r, c, grid, seen);
                    maxSize = max(maxSize, res);
                }
            }
        }
        
        return maxSize;
    }
};
