class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int lstday=1;
        for(auto it:events){
            lstday=max(lstday,it[1]);
        }
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int j=0;
        int ans=0;
        for(int i=1;i<=lstday;i++){
            while(j<n&&events[j][0]==i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty()&&pq.top()<i){
                pq.pop();
            }
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
            
        }
        return ans;

    }
};