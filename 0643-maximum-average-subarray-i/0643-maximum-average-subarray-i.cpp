class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        int maxi = sum;

        for(int i = k; i < nums.size(); i++)
        {
            sum = sum - nums[i-k];
            sum = sum + nums[i];

            if(sum > maxi)
            {
                maxi = sum;
            }
        }

        return (double)maxi / k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna