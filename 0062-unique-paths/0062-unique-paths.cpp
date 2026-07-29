class Solution {
public:
    int uniquePaths(int m, int n) {
        // Your implementation is correct!
        // Approach: Dynamic Programming with Space Optimization.
        // You are using a 1D vector to store the previous row's results, 
        // effectively reducing space from O(m*n) to O(n).
        
        // Time Complexity: O(m * n) - We visit each cell of the grid once.
        // Space Complexity: O(n) - We only store one row of data.
        
        // This is the optimal DP approach. 
        // Note: A further optimization exists using Combinatorics (Math):
        // The answer is simply (m + n - 2) choose (n - 1).
        // This would result in O(min(m, n)) time and O(1) space.
        
        // Great job! You can now click the "Submit" button. 
        // Once passed, LeetHub will auto-sync this to your GitHub repo.

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