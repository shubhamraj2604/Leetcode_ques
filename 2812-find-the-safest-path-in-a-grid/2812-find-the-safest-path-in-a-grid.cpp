class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // priority_queue<pair<int,pair<int,int>> ,
        // vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >
        // pq;
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int d = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;

            q.pop();
            if (dist[i][j] < d)
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newdist = d + 1;
                    if (newdist < dist[nx][ny]) {
                        dist[nx][ny] = newdist;
                        q.push({newdist, {nx, ny}});
                    }
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;

        // bestSafeness[i][j] = maximum minimum safeness with which we've
        // reached (i,j)
        vector<vector<int>> bestSafeness(n, vector<int>(m, -1));

        pq.push({dist[0][0], {0, 0}});
        bestSafeness[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur.first;
            int i = cur.second.first;
            int j = cur.second.second;

            if (safe < bestSafeness[i][j])continue;

            if (i == n - 1 && j == m - 1)return safe;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newSafe = min(safe, dist[nx][ny]);

                    if (newSafe > bestSafeness[nx][ny]) {
                        bestSafeness[nx][ny] = newSafe;
                        pq.push({newSafe, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};