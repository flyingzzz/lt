class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> userToDatas;
        unordered_map<string, int> threeSequencesToCounts;
        int maxCount = 0;
        string res;
        // Step 1: collect user data in a map of maps 
        // Basically store website and time data for every user name, by user name 
        for (auto i = 0; i < username.size(); ++i){
            userToDatas[username[i]][timestamp[i]] = website[i];
        }
        // Step 2: collect three sequences      
        for (auto userToData: userToDatas){
            unordered_set<string> threeSequences;
            // T :O(n^3)
            for (auto it = begin(userToData.second); it != end(userToData.second); ++it){   
                for (auto it1 = next(it); it1 != end(userToData.second); ++it1){
                    for (auto it2 = next(it1); it2 != end(userToData.second); ++it2){
                        threeSequences.insert(it->second + "$" + it1->second + "#" + it2->second);
                    }
                }
            }
            for (auto threeSequence : threeSequences) {
                ++threeSequencesToCounts[threeSequence];
            }
        }
        
        for (auto threeSequenceToCount : threeSequencesToCounts) {
            cout<< threeSequenceToCount.first<< " "<< threeSequenceToCount.second<< endl;
            if (threeSequenceToCount.second >= maxCount) {
                // If there is more than one solution, 
                //return the lexicographically smallest such 3-sequence.
                res = res == "" || threeSequenceToCount.second > maxCount ? threeSequenceToCount.first : min(res, threeSequenceToCount.first);
                maxCount = threeSequenceToCount.second;
            }
        }
        auto seperator1 = res.find("$");
        auto seperator2 = res.find("#");
  
        return { res.substr(0, seperator1),// element 1
                res.substr(seperator1 + 1, seperator2 - seperator1 - 1), // element 2
                res.substr(seperator2 + 1) };// element 3
    }
};
