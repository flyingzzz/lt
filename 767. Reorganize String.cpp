class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char, int> charNum;
        priority_queue<pair<int, char>> que;
        for(char c : s) {
            charNum[c]++;
        }
        
        for(auto element : charNum) {
            if(element.second > (s.size() + 1)/2) return "";
            que.push({element.second, element.first});
        }
        
        while(que.size() >= 2) {
            auto t1 = que.top(); que.pop();
            auto t2 = que.top(); que.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            t1.first--;
            t2.first--;
            if(t1.first > 0) que.push(t1);
            if(t2.first > 0) que.push(t2);
        }
        
        if(que.size() > 0) res.push_back(que.top().second);
        
        return res;
    }
};
