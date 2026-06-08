class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int q = target.size();
        vector<string> result = {};
        bool found = false;
        int matched = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < q; j++) {
                if (i == target[j]) {
                    found = true;
                    break;
                }
            }
            result.push_back("Push");
            if (found == false) {
                result.push_back("Pop");
            }
            else {
                matched++;
                if (matched == q) {break;}
            }
            found = false;
        }

        return result;
    }
};