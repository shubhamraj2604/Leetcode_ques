class Solution {
public:
    bool isprime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}
    vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

    int minJumps(vector<int>& nums) {
        queue<pair<int,int>>q;
        int n = nums.size();
        vector<int>dist(n, INT_MAX);
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<n;i++){
           vector<int>r = getPrimeFactors(nums[i]);
           for(auto c:r){
             m[c].push_back(i);
           }
        }


        q.push({0 , 0});
        dist[0] = 0;
        int dx[] = {-1 ,1};
        while(!q.empty()){
           int steps = q.front().first;
           int index = q.front().second;
           q.pop();
           for(int i=0;i<2;i++){
             int x = index + dx[i];
             if(x >=0 && x<n && steps + 1< dist[x]){
                dist[x] = steps + 1;
                q.push({steps+1 , x});
             }
           }

           if(isprime(nums[index])){
              for(auto c:m[nums[index]]){
                if(c!=index && steps + 1 < dist[c]){
                    dist[c] = steps + 1;
                    q.push({steps +1 , c});
                }
              }
           }
           m[nums[index]].clear();
        }

        return dist[n-1];
    }
};