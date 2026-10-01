class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;
    void dfs1(int u, int parent, int &count) {
        for(auto [v, cost] : adj[u]) {
            if(v == parent)continue;
            count += cost;
            dfs1(v, u, count);
        }
    }

    void dfs2(int u, int parent) {
        for(auto [v, cost] : adj[u]) {
            if(v == parent)continue;
            if(cost == 0) {
                ans[v] = ans[u] + 1;
            }
            else{
                ans[v] = ans[u] - 1;
            }

            dfs2(v, u);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.resize(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        int count = 0;
        dfs1(0, -1, count);
        ans[0] = count;
        dfs2(0, -1);
        return ans;
    }
};