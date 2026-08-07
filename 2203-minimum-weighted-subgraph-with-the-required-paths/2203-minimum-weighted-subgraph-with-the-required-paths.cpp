class Solution {
public:
    vector<long long> dijkstra(int n, vector<vector<pair<int,long long>>>& adj, int src) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dist[node]) continue;
            for (auto &it : adj[node]) {
                int next = it.first;
                long long wt = it.second;
                if (dist[next] > d + wt) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,long long>>> adj(n), rev(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }
        auto d1 = dijkstra(n, adj, src1);
        auto d2 = dijkstra(n, adj, src2);
        auto d3 = dijkstra(n, rev, dest);

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX || d3[i] == LLONG_MAX) continue;
            ans = min(ans, d1[i] + d2[i] + d3[i]);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};