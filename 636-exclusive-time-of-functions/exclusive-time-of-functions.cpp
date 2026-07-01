class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n, 0);
    stack<int> st;
    int prev = 0;
    for (int i = 0; i < logs.size(); i++) {
        const string& log = logs[i];
        int c1 = log.find(':'), c2 = log.rfind(':');
        int id   = stoi(log.substr(0, c1));
        string type = log.substr(c1+1, c2-c1-1);
        int time = stoi(log.substr(c2+1));
        if (type == "start") {
            if (!st.empty())
                result[st.top()] += time - prev;
            st.push(id);
            prev = time;
        } else {
            result[st.top()] += time - prev + 1;
            st.pop();
            prev = time + 1;
        }
    }
    return result;
}
};