class TimeMap {
private:
    unordered_map<string, map<int, string>> mm;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mm[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mm[key].upper_bound(timestamp);
        if (it == mm[key].begin()) {
            return "";
        }
        it--;
        return it->second; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */