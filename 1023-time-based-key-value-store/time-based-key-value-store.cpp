class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }

    void set(string key, string value, int timestamp) {
        store[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        
        vector<pair<int, string>>& values = store[key];
        int lo = 0, hi = (int)values.size() - 1;
        int resultIdx = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (values[mid].first <= timestamp) {
                resultIdx = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return resultIdx == -1 ? "" : values[resultIdx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */