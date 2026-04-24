class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dist = 0;
        int left = 0 , right = 0 , d = 0;
        for(auto c:moves){
            if(c == 'L'){
                left++;
            }else if(c == 'R'){
                right++;
            }else{
                d++;
            }
        }

        return left > right ? (left + d) - right : (right + d) - left;
    }
};