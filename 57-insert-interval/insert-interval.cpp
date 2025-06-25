class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int s1=intervals[i][0];
            int e1=intervals[i][1];
            if(s1<=end){
                end=max(end,e1);
            }
            else{
                ans.push_back({start,end});
                start=s1;
                end=e1;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};