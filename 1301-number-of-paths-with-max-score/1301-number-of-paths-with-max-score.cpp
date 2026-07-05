class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>>newboard(n , vector<int>(n , 0));

        for(int i=0;i<n;i++){
            string x = board[i];
            for(int j=0;j<n;j++){
                if(x[j] == 'X'){
                    newboard[i][j] = -1;
                }else if(x[j] == 'S' || x[j] == 'E'){
                    newboard[i][j] = 0;
                }else newboard[i][j] = x[j] - '0';
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<newboard[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        queue<pair<int, pair<int,int>> >q;
        q.push({0 ,{n-1 , n-1}});
        vector<vector<int>>dist(n , vector<int>(n , INT_MIN));
        vector<vector<int>>cnt(n , vector<int>(n , 0));
        dist[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;
        int dx[] = {-1,-1 , 0};
        int dy[] = {-1 , 0 , -1};
        while(!q.empty()){
            int curr_sum = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            for(int k=0;k<3;k++){
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(nx < n && nx>=0 && ny<n && ny>=0 && newboard[nx][ny] != -1){
                    int newval = (newboard[nx][ny]) + curr_sum;

                    if(newval > dist[nx][ny]){
                       dist[nx][ny] = newval;
                       cnt[nx][ny] = cnt[i][j];
                       q.push({newval , {nx , ny}});
                    }else if(newval == dist[nx][ny]){
                        cnt[nx][ny] = (cnt[nx][ny] + cnt[i][j]) % mod;
                    }
                }
            }
        }
        if(dist[0][0] == INT_MIN){
            return {0 , 0};
        }
        return {dist[0][0] , cnt[0][0]};
    }
};