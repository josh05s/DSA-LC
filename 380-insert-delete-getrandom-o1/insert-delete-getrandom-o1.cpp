class RandomizedSet {
public:
    std::vector<int> values;
    std::unordered_map<int, int> indexOf;

    RandomizedSet() {

    }

    bool insert(int val) {
        if (indexOf.find(val) != indexOf.end()) return false;
        indexOf[val] = values.size();
        values.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (indexOf.find(val) == indexOf.end()) return false;
        int idx = indexOf[val];
        int lastVal = values.back();
        values[idx] = lastVal;
        indexOf[lastVal] = idx;
        values.pop_back();
        indexOf.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % values.size();
        return values[idx];
    }
};