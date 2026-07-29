class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n, 1);

        for (int i = 1; i < m; i++) {
            vector<int> curr(n, 1);

            for (int j = 1; j < n; j++) {
                curr[j] = prev[j] + curr[j - 1];
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna