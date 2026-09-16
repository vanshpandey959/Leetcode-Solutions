class Solution {
public:
    int M = 1e9 + 7;

    int numberOfSets(int n, int K) {

        // dp[i] = previous row: dp[k-1][i]
        vector<int> dp(n + 1, 0);

        // Base case: dp[0][i] = 1 for i < n
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> curr(n + 1, 0);
            vector<int> prevRowSum(n + 1, 0);

            // Suffix sum of previous row
            for (int i = n - 1; i >= 0; i--) {
                prevRowSum[i] =
                    (prevRowSum[i + 1] + dp[i]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {

                // skip i
                int skip = curr[i + 1];

                // take i
                int take = prevRowSum[i + 1];

                curr[i] = (take + skip) % M;
            }

            dp = curr;
        }

        return dp[0];
    }
};