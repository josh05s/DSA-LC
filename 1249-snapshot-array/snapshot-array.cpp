class SnapshotArray {
public:
    vector<vector<pair<int,int>>> history;
    int curr_snap_id;

    SnapshotArray(int length) {
        history.resize(length);
        for (int i = 0; i < length; i++) {
            history[i].push_back(make_pair(0, 0));
        }
        curr_snap_id = 0;
    }

    void set(int index, int val) {
        int size = history[index].size();
        if (size > 0 && history[index][size - 1].first == curr_snap_id) {
            history[index][size - 1].second = val;
        } else {
            history[index].push_back(make_pair(curr_snap_id, val));
        }
    }

    int snap() {
        return curr_snap_id++;
    }

    int get(int index, int snap_id) {
        vector<pair<int,int>>& v = history[index];
        int lo = 0, hi = (int)v.size() - 1;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid].first <= snap_id) {
                ans = v[mid].second;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};