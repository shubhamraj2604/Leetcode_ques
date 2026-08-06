class Solution {
public:
    int d(int n){
        int prod = 1;
        while(n!=0){
            prod*=n % 10;
            n/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
         for(int i=n;i<=100;i++){
            int x = d(i);
            if(x % t == 0){
                return i;
            }
         }
         return 0;
    }
};