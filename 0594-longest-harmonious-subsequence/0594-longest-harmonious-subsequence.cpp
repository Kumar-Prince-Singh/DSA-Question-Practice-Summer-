class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            
            while (nums[right] - nums[left] > 1) {
                left++;
            }

            if (nums[right] - nums[left] == 1) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna