class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

       
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {

                    if(dist[i][k] != 1e9 &&
                       dist[k][j] != 1e9) {

                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int city = -1;
        int minReachable = 1e9;

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(dist[i][j] <= distanceThreshold)
                    count++;
            }

            if(count <= minReachable) {
                minReachable = count;
                city = i;
            }
        }

        return city;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna