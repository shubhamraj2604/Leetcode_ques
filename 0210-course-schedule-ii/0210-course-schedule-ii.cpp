class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < prerequisites.size() ; i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            visited[v]++;
        }

        queue<int>q;

        // for(int i=0;i<adj.size();i++){
        //     for(auto c:adj[i]){
        //         visited[c]++; //incoming degree
        //     }
        // }

        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0) {
                q.push(i);
            }
        }


        vector<int>ans;
        while (!q.empty()) { 
            int r = q.front();
            ans.push_back(r);
            q.pop();

            for (auto it : adj[r]) {
                visited[it]--;
                if(visited[it] == 0){
                    q.push(it);
                }
            }
        }

      if (ans.size() != numCourses) return {};
        return ans;
    }
};