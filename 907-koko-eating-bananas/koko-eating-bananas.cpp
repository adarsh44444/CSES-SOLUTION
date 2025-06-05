class Solution {
public:
#define ll long long
bool cansolve(vector<int> &piles,ll mid,int h,int n){
    ll cnt=0;
    for(int i=0;i<n;i++){
        cnt+=ceil((1.0*piles[i])/mid);
    }
    return cnt<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        ll n=piles.size();
        ll low=1,high=1e9;
        while(low<=high){
            ll mid=(low+high)/2;
            if(cansolve(piles,mid,h,n)) high=mid-1;
            else low=mid+1;
        }
        return high+1;
    }
};