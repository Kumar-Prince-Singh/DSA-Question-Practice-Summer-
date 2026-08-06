class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int right=1;
        int result=0;
        for(int right=1; right<nums.size(); right++ ){
            if(nums[right] != nums[left]){
                left++;
                nums[left]=nums[right];

            }
        }
        return left+1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna