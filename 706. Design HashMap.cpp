class MyHashMap {
private:
    //becareful to inintialize the hash_table
    //*iter.first cannot work. should be (iter->first or (*iter).first)
    //must return from loop when erase one item
    vector<list<pair<int,int>>> hash_table{vector<list<pair<int,int>>>(2069)};
    //vector<list<pair<int,int>>> hash_table;
    const int key_space = 2069;
public:
    MyHashMap() {
        //hash_table.resize(key_space);
    }
    
    void put(int key, int value) {
        int hash_key = key % key_space;
        for(auto iter = hash_table[hash_key].begin(); iter != hash_table[hash_key].end(); ++iter) {
            if(iter->first == key) {
                iter->second = value;
                return;
            }
        }
        hash_table[hash_key].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int hash_key = key % key_space;
        for(auto iter = hash_table[hash_key].begin(); iter != hash_table[hash_key].end(); ++iter) {
            if(iter->first == key) {
                return iter->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = key % key_space;
        for(auto iter = hash_table[hash_key].begin(); iter != hash_table[hash_key].end(); ++iter) {
            if(iter->first == key) {
                hash_table[hash_key].erase(iter);
                //must return
                return;
            }
        }
        return;
    }
};
