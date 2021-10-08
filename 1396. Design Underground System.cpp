class UndergroundSystem {
private:
    //注意，journeyData pair 不能是float float，否则提交失败,这里和java不太一样
    //当hashmap不存在 key 的时候，返回的为 0 值 而不是空值
    unordered_map<string, pair<int, int>> journeyData;
    unordered_map<int, pair<string, int>> checkInData;
    
    string stationsKey(string startStation, string endStation) {
        return startStation + "->" + endStation;
    }
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInData[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> checkInDataForId = checkInData[id];
        string startStation = checkInDataForId.first;
        int checkInTime = checkInDataForId.second;
        
        string routeKey = stationsKey(startStation, stationName);
        pair<int, int> routeStats = journeyData[routeKey];
        
        int tripTime = t - checkInTime;
        journeyData[routeKey] = make_pair(routeStats.first + tripTime, routeStats.second + 1);
        
        checkInData.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeKey = stationsKey(startStation, endStation);
        pair<int, int> timeTrip = journeyData[routeKey];
        
        return static_cast<double> (timeTrip.first)/timeTrip.second;
    }
};
