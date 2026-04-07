class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // unordered_map<int,int>m;
        // vector<int>ans;
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid.size();j++){
        //        m[grid[i][j]]++;
        //        if(m[grid[i][j]]==2){
        //         ans.push_back(grid[i][j]);
        //        }
        //     }
        // }

        int number=grid.size();
        // for(int i=1;i<=n*n;i++){
        //     if(m.find(i)==m.end())ans.push_back(i);
        // }
        
        int n = number * number;
        int total_sum = (n * (n+1))/2;
        long long total_sum_squares = ((long long)n * (n + 1) * (2*n + 1))/6;
        long long sum= 0 , sums=0;
        for(auto c:grid){
            for(auto x:c){
                sum+=x;
                sums+=(x*x);
            }
        }

        long long diff = total_sum - sum;
        long long diffs = total_sum_squares - sums;

        long long sum_ab = diffs / diff;

        long long a = (sum_ab + diff)/2;

        long long b = a - diff;

        return {(int)b , (int)a} ;
    }
};