class DSU{
    vector<int>rank;
    vector<int>parent;
    public:
    DSU(int n){
      rank.resize(n,0);
      parent.resize(n , 0);
      for(int i=0;i<n;i++){
         parent[i] = i;
      }
    }


    int findULP(int u){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = findULP(parent[u]);
    }


    void unionbyrank(int u , int v){
        int ulp_u = findULP(u);
        int ulp_v = findULP(v);

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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
      int m = queries.size();  
      vector<bool> ans(m , false);
      DSU ds(n);
      for(int i=1;i<n;i++){
        int diff = nums[i] - nums[i-1];
        if(diff <= maxDiff){
            ds.unionbyrank(i-1, i);
        }
      }

      int i = 0;
      for(auto c:queries){
         int u = c[0];
         int v = c[1];
         if(ds.findULP(u) == ds.findULP(v)){
            ans[i] = true;
         }
         i++;
      }

      return ans; 
    }
};