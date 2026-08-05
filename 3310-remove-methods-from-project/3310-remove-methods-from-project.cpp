class Solution {
public:
    vector<vector<int>>adj;
    void dfs(vector<int>&harm , int node){
        harm[node] = 1;

        for(auto c:adj[node]){
            if(!harm[c])dfs(harm , c);
        }
    }

    // bool dfs1(vector<int>&visited , int node , vector<int>&harm){
    //     visited[node] = 1;
    //     for(auto c:adj[node]){
    //         if(harm[c] == 1){
    //             return true;
    //         }
    //         if(!visited[c] && dfs1(visited , c , harm))return true;
    //     }
    //     return false;
    // }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // find the nodes which are in contact with 
        vector<int>harm(n , 0);
        adj.resize(n);
        for(auto c:invocations){
            adj[c[0]].push_back(c[1]);
        }
        dfs(harm , k);
        
        for(auto c:invocations){
            int a = c[0];
            int b = c[1];
             
            if(!harm[a] && harm[b]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!harm[i]){
                ans.push_back(i);
            }
        }
    return ans;
    } 
};