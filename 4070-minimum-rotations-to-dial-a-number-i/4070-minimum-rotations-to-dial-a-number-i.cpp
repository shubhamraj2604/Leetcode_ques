class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int ans = 0;
        int currp=0;
        for(int i=0;i<n;i++){
            int t = s[i] - '0';
            int diff = abs(t - currp);
            int mini = min(diff , 10 - diff);
            ans+=mini;
            currp = s[i] - '0';
        }
        return ans;
    }
};