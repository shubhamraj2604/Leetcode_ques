class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            vector<int>&a = ans.back();
            if(a[1]<start){
                ans.push_back({start , end});
            }else{
                a[1] = max(a[1] , end);
            }
        }
        return ans;
    }
};