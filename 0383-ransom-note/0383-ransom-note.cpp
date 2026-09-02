class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        for(char ch : magazine) {
            freq[ch - 'a']++;
        }

        for(char ch : ransomNote) {
            freq[ch - 'a']--;

            if(freq[ch - 'a'] < 0)
                return false;
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna