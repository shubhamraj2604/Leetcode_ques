class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // sum of n terms 
        // (n/2)(2*a + (n - 1)d);
        int even = n * (4 + (n - 1)*2) / 2;
        int odd = n*(2 + (n-1)*2)/2;
        cout<<even<<" "<<odd;
        return gcd(even , odd);
    }
};