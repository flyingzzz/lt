class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        /*sort(items.begin(), items.end(),
            [](const vector<int> &a, const vector<int> &b) {
                if (a[0] != b[0])
                return a[0] < b[0]; 
                return a[1] > b[1];
            });*/
        vector<vector<int>> ans;
        map<int, priority_queue<int>> allScores;
        for(auto item : items) {
            allScores[item[0]].push(item[1]);
        }
        
        for(auto &[id, scores] : allScores) {
            int sum = 0;
            for(int i = 0; i < 5; ++i) {
                sum += scores.top();
                scores.pop();
            }
            ans.push_back({id, sum/5});
        }
        return ans;
    }
};
