class DSU{
    public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        rank.resize(n , 0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }


    int findparent(int u){
        if(parent[u] == u){
            return u;
        }

        return parent[u] = findparent(parent[u]);
    }

    void ubyrank(int u , int v){
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);

        if(ulp_u == ulp_v)return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      unordered_map<int , int>l,m;
      int n = stones.size();
      DSU ds(n);
      for(int i=0;i<n;i++){
          int x = stones[i][0];
          int y = stones[i][1];

          if(l.count(x)){
            ds.ubyrank(l[x] , i);
          }

          if(m.count(y)){
            ds.ubyrank(m[y] , i);
          }

          l[x] = i;
          m[y] = i;
      }

    int cnt = 0;
      for(int i=0;i<n;i++){
        int p = ds.findparent(i);
         if(i == p){
            cnt++;
         }
      }
      return n - cnt; 
    } 
};