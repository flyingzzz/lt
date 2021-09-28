class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dirIndex = 0; // 0 north, 1 east, 2 south, 3 west
        vector<int> cur {0, 0};
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(char ins : instructions) {
            if(ins == 'G') {
                cur = {cur[0] + dirs[dirIndex][0], cur[1] + dirs[dirIndex][1]};
            }
            else if(ins == 'L') {
                dirIndex = (dirIndex + 4 - 1)%4;
            } else {
                dirIndex = (dirIndex + 1) %4;
            }
        }
        
        if((cur[0] == 0 && cur[1] == 0) || dirIndex > 0)
            return true;
        else 
            return false;
    }
};
