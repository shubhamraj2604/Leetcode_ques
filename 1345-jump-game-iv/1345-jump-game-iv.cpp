class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>m;
        int index = 0;
        for(auto c:arr){
            m[c].push_back(index);
            index++;
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0 , arr[0]}});
        vector<int>dist(n , INT_MAX);
        dist[0] = 0;
        int dir[] = {-1 , 1};
        while(!q.empty()){
           int jump = q.front().first;
           int index = q.front().second.first;
           int val = q.front().second.second;
           q.pop();
        if(index == n-1)return jump;
           for(auto c:dir){
              int dx = index + c;
 
              if(dx>=0 && dx<n){
                if(jump + 1 < dist[dx]){
                    dist[dx] = jump + 1;
                    q.push({jump + 1 , {dx , arr[dx]}});
                }
              }
           }

           for(auto x:m[val]){
                if(x!=index){
                  if(jump + 1 < dist[x]){
                    dist[x] = jump+1;
                    q.push({jump + 1 , {x , arr[x]}});
                  }
                }
           }

            m[arr[index]].clear();
        }


        return dist[n-1];
    }
};