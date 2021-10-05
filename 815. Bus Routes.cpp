class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int res = 0;
        unordered_map<int, unordered_set<int>> stop2bus;
        queue<int> q{{source}};
        unordered_set<int> visitedBus;
        if(source == target) {
            return 0;
        }
        
        for(int i = 0 ; i < routes.size(); i++) {
            for(int j : routes[i]) {
                stop2bus[j].insert(i);
            }
        }
        
        while(!q.empty()) {
            res++;
            for(int i = q.size(); i > 0; --i) {
                int stop = q.front(); q.pop();
                for(int bus : stop2bus[stop]) {
                    if(visitedBus.count(bus) > 0) {
                        continue;
                    } else {
                        visitedBus.insert(bus);
                        for(int stop : routes[bus]) {
                            if(stop == target) {
                                return res;
                            }
                            q.push(stop);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
