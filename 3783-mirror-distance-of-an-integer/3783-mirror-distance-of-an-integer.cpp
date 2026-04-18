class Solution {
public:
    int reverse(int n){
        int ans = 0;
        while(n!=0){
            int rev = n % 10;
            n/=10;
            ans = ans * 10 + rev;
        }

        return ans;
    }
    int mirrorDistance(int n) {
        int mirror = reverse(n);
        return abs(n - mirror);
    }
};