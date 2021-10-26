class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        int usedBox = 0;
        sort(boxTypes.begin(), boxTypes.end(), 
             [](vector<int> a, vector<int> b){return a[1] > b[1];});
        for(auto box : boxTypes) {
            if(box[0] <= truckSize - usedBox) {
                usedBox += box[0];
                res += box[0]*box[1];
            } else {
                res += box[1]*(truckSize - usedBox);
                break;
            }
        }
        
        return res;
    }
};
/*
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> queue;
        for (auto boxType : boxTypes) {
            queue.push(boxType);
        }
        int unitCount = 0;
        while (!queue.empty()) {
            vector<int> top = queue.top();
            queue.pop();
            int boxCount = min(truckSize, top[0]);
            unitCount += boxCount * top[1];
            truckSize -= boxCount;
            if(truckSize == 0)
                break;
        }
        return unitCount;
    }

    struct Comparator {
        bool operator()(vector<int> const& p1, vector<int> const& p2) {
            return p1[1] < p2[1];
        }
    };
*/
