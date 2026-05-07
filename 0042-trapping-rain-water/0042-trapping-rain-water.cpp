class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // vector<int>leftmax(n,0);
        // leftmax[0] = height[0];
        // for(int i=1;i<n;i++){
        //   leftmax[i] = max(leftmax[i-1] , height[i]);
        // }

        // vector<int>rightmax(n,0);
        // rightmax[n-1] = height[n-1];
        
        // for(int i=n-2 ;i>=0;i--){
        //    rightmax[i] = max(rightmax[i+1] , height[i]); 
        // }
        

        int ans = 0;
        // for(int i=0;i<n;i++){
        //     ans+= min(rightmax[i] , leftmax[i]) - height[i];
        // }

        int lmax = 0 , rmax = 0 , l = 0 , r = n-1;
        while(l<r){
            if(height[l] <= height[r]){
                if(lmax > height[l]){
                    ans+=lmax - height[l];
                }else{
                    lmax = height[l];
                }
                l++;
            }else{
                if(rmax>height[r]){
                    ans+=rmax - height[r];
                }else{
                    rmax = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};