class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
      vector<vector<pair<int,int>>>adj(n);
      for(auto c:roads){
        int u = c[0];
        int v = c[1];
        int time = c[2];
        adj[u].push_back({v , time});
        adj[v].push_back({u , time});
      } 


      priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> > pq;
      pq.push({0 , 0});

      vector<long long>dist(n , LLONG_MAX);
      vector<int>visited(n , 0);
      dist[0] = 0;
      visited[0] = 1;
      const int mod = 1e9 + 7;
      while(!pq.empty()){
        long long t = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto c:adj[node]){
            long long new_time = 1LL * t + c.second;
            int newnode = c.first;
            if(new_time < dist[newnode]){
                dist[newnode] = new_time;
                visited[newnode] = visited[node];
                pq.push({new_time , newnode});
            }else if(new_time == dist[newnode]){
                visited[newnode] = (visited[newnode] + visited[node]) % mod ;
            }
        }
      }

      return visited[n-1]; 
    } 
};