class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dataMap[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = dataMap[key].upper_bound(timestamp);
        return it == dataMap[key].begin() ? "" : prev(it)->second;
    }
private:
    unordered_map<string, map<int, string>> dataMap;
};
