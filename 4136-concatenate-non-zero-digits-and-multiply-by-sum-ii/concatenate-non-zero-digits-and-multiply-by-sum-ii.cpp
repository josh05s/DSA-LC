class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> val(n + 1, 0);    
        vector<long long> cnt(n + 1, 0);     
        vector<long long> digitSum(n + 1, 0); 

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            digitSum[i + 1] = digitSum[i] + d;
            if (d != 0) {
                val[i + 1] = (val[i] * 10 + d) % MOD;
                cnt[i + 1] = cnt[i] + 1;
            } else {
                val[i + 1] = val[i];
                cnt[i + 1] = cnt[i];
            }
        }

        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long cntRange = cnt[r + 1] - cnt[l];
            long long x = ((val[r + 1] - val[l] * pow10[cntRange]) % MOD + MOD) % MOD;
            long long sum = digitSum[r + 1] - digitSum[l];
            long long res = (x * (sum % MOD)) % MOD;
            ans.push_back((int)res);
        }

        return ans;
    }
};