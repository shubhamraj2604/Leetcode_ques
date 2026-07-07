class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long new_no = 0;
        while(n!=0){
            long long rev = n%10;
            n/=10;
            if(rev != 0){
              new_no = new_no * 10 + rev;
            }
            sum+=rev;
        }
        long long x = 0;
        while(new_no != 0){
            long long rev = new_no % 10;
            new_no/=10;
            x = x* 10 + rev;
        }
        return 1LL * sum * x ;
    }
};