class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), res = 0;
        queue<int> q{{1}};
        vector<bool> visited(n * n + 1);
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                int num = q.front(); q.pop();
                if (num == n * n) return res;
                for (int i = 1; i <= 6 && num + i <= n * n; ++i) {
                    auto pos = getPosition(num + i, n);
                    int next = board[pos[0]][pos[1]] == -1 ? (num + i) : board[pos[0]][pos[1]];
                    if (visited[next]) continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            ++res;
        }
        return -1;
    }
    vector<int> getPosition(int num, int n) {
        int row = (num - 1) / n, col = (num - 1) % n;
        if (row % 2 == 1) col = n - 1 - col;
        row = n - 1 - row;
        return {row, col};
    }
};
