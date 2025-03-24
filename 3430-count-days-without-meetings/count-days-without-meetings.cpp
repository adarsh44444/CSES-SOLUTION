class Solution {
public:
#define ll long long
    int countDays(int days, vector<vector<int>>& meetings) {
        ll n=meetings.size();
        sort(meetings.begin(),meetings.end());
        ll maxi=meetings[0][1];
        ll cnt=0;
        cnt+=meetings[0][0]-1;
        for(int i=1;i<n;i++){
            if(meetings[i][0]>maxi+1){
                cnt+=meetings[i][0]-(maxi+1);
            }
            if(maxi<meetings[i][1]){
                maxi=meetings[i][1];
            }
        }
        cnt+=days-maxi;
        return cnt;
    }
};