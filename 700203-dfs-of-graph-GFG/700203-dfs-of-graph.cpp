class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited) {
        visited[node] = true;
        ans.push_back(node);

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                DFS(neighbour, adj, ans, visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();              
        vector<int> ans;
        vector<bool> visited(V, false);

        DFS(0, adj, ans, visited);       

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna