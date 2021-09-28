class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string, int> subdomainCnt;
        for(string cpdomain: cpdomains) {
            int spaceIndex = cpdomain.find(" ");
            int cnt = stoi(cpdomain.substr(0, spaceIndex));
            string rem = cpdomain.substr(spaceIndex + 1);
            for(int i = 0; i < rem.length(); i++) {
                if(rem[i] == '.') {
                    string partdomain = rem.substr(i + 1);
                    subdomainCnt[partdomain] += cnt;
                }
            }
            subdomainCnt[rem] += cnt;
        }
        
        for(auto subCnt : subdomainCnt) {
            res.push_back(to_string(subCnt.second) + " " + subCnt.first);
        }
        
        return res;
    }
};
