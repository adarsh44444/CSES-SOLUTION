class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(end<intervals[i][0]){
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                end=max(end,intervals[i][1]);
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};