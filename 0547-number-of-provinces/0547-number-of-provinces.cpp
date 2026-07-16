class Solution {
private:
    void dfs(int src, vector<vector<int>>& isConnected,
             vector<bool>& vis)
    {
        vis[src] = true;

        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++)
        {
            if (isConnected[src][neighbour] == 1 &&
                !vis[neighbour])
            {
                dfs(neighbour, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        vector<bool> vis(n, false);

        int province = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, isConnected, vis);
                province++;
            }
        }

        return province;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna