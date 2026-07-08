class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();

       vector<int>leftheight(n);
       leftheight[0] = height[0];

       for(int i=1;i<n;i++){
          leftheight[i] = max(leftheight[i-1] , height[i]);
       }
       vector<int>rightheight(n);
       rightheight[n-1] = height[n-1];
       for(int i=n-2;i>=0;i--){
        rightheight[i] = max(rightheight[i+1] , height[i]);
       }
       int ans = 0;
       for(int i=0;i<n;i++){
         ans+= min(leftheight[i] , rightheight[i]) - height[i];
       }

       return ans;
    }
};