class Solution {
public:
    int minKnightMoves(int x, int y) {
         // the offsets in the eight directions
        vector<vector<int>> offsets = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        
        bool visited[605][605];

        queue<pair<int, int>> que;
        que.push({0, 0});
        int steps = 0;
        
        while (que.size() > 0) {
            int currLevelSize = que.size();
            // iterate through the current level
            for (int i = 0; i < currLevelSize; i++) {
                auto curr = que.front(); que.pop();
                if (curr.first == x && curr.second == y) {
                    return steps;
                }

                for (vector<int> offset : offsets) {
                    vector<int> next{curr.first + offset[0], curr.second + offset[1]};
                    // align the coordinate to the bitmap
                    if (!visited[next[0] + 302][next[1] + 302]) {
                        visited[next[0] + 302][next[1] + 302] = true;
                        que.push({next[0], next[1]});
                    }
                }
            }
            steps++;
        }
        // move on to the next level
        return steps;
    }
};
