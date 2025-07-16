class Solution {
public:
#define ll long long
bool solve(ll mid,vector<int> &nums,int threshold){
    ll n=nums.size();
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((1.0*nums[i])/mid);
    }
    return sum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        ll low=1;
        ll high=accumulate(nums.begin(),nums.end(),0ll);
        ll mid;
        ll ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(solve(mid,nums,threshold)){ans=mid; high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
};