class Solution {
public:
#define ll long long 
    ll solve(vector<int> &time,int totalTrips, ll mid){
        ll cnt=0;
        for(int i=0;i<time.size();i++){
            cnt+=mid/time[i];
        }
        return cnt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low=1;
        ll high=1e14;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            if(solve(time,totalTrips,mid)>=totalTrips){
                high=mid-1;
            }
            else low=mid+1;
        }
        return high+1;;

    }
};