class TimeMap {
    // string key;
    // string value;
    // int timestamp;
    //multimap<string,multimap<int,string>>m;
    unordered_map<string,map<int,string>>m;
public:
    TimeMap() {
        // key = "";
        // value = "";
        // timestamp = 0;
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp,value});    
    }
    
    string get(string key, int timestamp) {
        
        if(m.count(key) == 0)
            return "";

        auto it = m[key].lower_bound(timestamp);

        if(it->first == timestamp)
            return it->second;
        else {
            return it == m[key].begin()? "":(prev(it))-> second;
         }
    }
};
