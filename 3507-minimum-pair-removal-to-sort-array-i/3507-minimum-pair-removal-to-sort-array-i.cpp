class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        auto isSorted = [](const vector<int>& arr) {
            for (int i = 1; i < arr.size(); ++i) {
                if (arr[i] < arr[i - 1]) return false;
            }
            return true;
        };

        while (!isSorted(nums)) {
            int minSum = nums[0] + nums[1];
            int idx = 0;

            for (int i = 1; i < nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            ans++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna