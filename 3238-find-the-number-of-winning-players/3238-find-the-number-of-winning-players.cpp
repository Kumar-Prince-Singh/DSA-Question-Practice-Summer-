class Solution {
public:
    int winningPlayerCount(int n, std::vector<std::vector<int>>& pick) {
        // Since colors typically range from 0 to 10 (or up to pick constraints),
        // we can use a 2D table: count[player][color]
        // Given constraints: player < n <= 10, color <= 10
        std::vector<std::vector<int>> color_count(n, std::vector<int>(11, 0));
        
        for (const auto& p : pick) {
            int player = p[0];
            int color = p[1];
            color_count[player][color]++;
        }
        
        int winners = 0;
        for (int i = 0; i < n; ++i) {
            for (int color = 0; color <= 10; ++color) {
                if (color_count[i][color] > i) {
                    winners++;
                    break; // Player i already won, don't count twice
                }
            }
        }
        
        return winners;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna