class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // see the constraints and use long long 
        vector<long long> row(n);
        vector<long long> col(m);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
            total += sum;
            row[i] = sum;
        }

        for (int i = 0; i < m; i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[j][i];
            }
            col[i] = sum;
        }

        long long curr = 0;
        for (int i = 0; i < n - 1; i++) {
            curr += row[i];
            long long nxsum = total - curr;
            if (curr == nxsum)return true;
        }

        curr = 0;
        for (int i = 0; i < m - 1; i++) {
            curr += col[i];
           long long nxsum = total - curr;
           if (curr == nxsum)return true;
        }

        return false;
    }
};