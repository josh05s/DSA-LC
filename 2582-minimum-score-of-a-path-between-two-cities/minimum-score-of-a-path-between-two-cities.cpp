class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < roads.size(); i++) {
            int a = roads[i][0], b = roads[i][1], d = roads[i][2];
            adj[a].push_back(make_pair(b, d));
            adj[b].push_back(make_pair(a, d));
        }

        vector<bool> visited(n + 1, false);
        stack<int> st;
        st.push(1);
        visited[1] = true;

        int minDist = INT_MAX;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i].first;
                int dist = adj[node][i].second;
                minDist = min(minDist, dist);
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    st.push(neighbour);
                }
            }
        }

        return minDist;
    }
};