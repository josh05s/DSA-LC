#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int maxV = 0;
        for (int x : nums) maxV = max(maxV, x);

        // dp[g1][g2] = number of ways to have partial GCD g1 for seq1
        // and partial GCD g2 for seq2 (0 means that sequence is still empty)
        vector<vector<long long>> dp(maxV + 1, vector<long long>(maxV + 1, 0));
        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<long long>> ndp = dp; // "skip this element" case

            for (int g1 = 0; g1 <= maxV; g1++) {
                for (int g2 = 0; g2 <= maxV; g2++) {
                    long long val = dp[g1][g2];
                    if (val == 0) continue;

                    int ng1 = (g1 == 0) ? num : (int)gcd(g1, num);
                    int ng2 = (g2 == 0) ? num : (int)gcd(g2, num);

                    // assign num to seq1
                    ndp[ng1][g2] = (ndp[ng1][g2] + val) % MOD;
                    // assign num to seq2
                    ndp[g1][ng2] = (ndp[g1][ng2] + val) % MOD;
                }
            }
            dp = move(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= maxV; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }
        return (int)ans;
    }
};