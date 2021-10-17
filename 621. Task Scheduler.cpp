class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencies(26, 0);
        if(n == 0) {
            return tasks.size();
        }
        for(auto i : tasks) {
            ++frequencies[i - 'A'];
        }
        
        sort(frequencies.begin(), frequencies.end());
        
        int f_max = frequencies[25];
        int idle_time = (f_max - 1) * n;
        for(int i = 24; i >= 0 && idle_time > 0; --i) {
            idle_time -= min(f_max - 1, frequencies[i]);
        }
        idle_time = max(0, idle_time);
        
        return tasks.size() + idle_time;
    }
};
