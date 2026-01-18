class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // cost[j][d] = operations to make column j all digit d
        vector<vector<int>> cost(n, vector<int>(10, 0));

        for (int j = 0; j < n; j++) {
            vector<int> freq(10, 0);
            for (int i = 0; i < m; i++) {
                freq[grid[i][j]]++;
            }
            for (int d = 0; d <= 9; d++) {
                cost[j][d] = m - freq[d];
            }
        }

        // dp[j][d]
        vector<vector<int>> dp(n, vector<int>(10, 1e9));

        // Base case: first column
        for (int d = 0; d <= 9; d++) {
            dp[0][d] = cost[0][d];
        }

        // Fill DP
        for (int j = 1; j < n; j++) {
            for (int d = 0; d <= 9; d++) {
                for (int prev = 0; prev <= 9; prev++) {
                    if (prev != d) {
                        dp[j][d] = min(dp[j][d],
                                        dp[j - 1][prev] + cost[j][d]);
                    }
                }
            }
        }

        // Answer
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
