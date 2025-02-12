class Solution {
public:
#define ll long long
    int maximumSum(vector<int>& nums) {
        ll n=nums.size();
        map<ll,vector<ll>> mp;
        for(ll i=0;i<n;i++){
            string temp=to_string(nums[i]);
            ll sum=0;
            for(ll j=0;j<temp.size();j++){
                sum+=temp[j]-'0';
            }
            mp[sum].push_back(nums[i]);
        }
        ll ans=-1;
        for(auto it:mp){
            sort(mp[it.first].rbegin(),mp[it.first].rend());
            if(mp[it.first].size()>=2){
            ans=max(ans,mp[it.first][0]+mp[it.first][1]);
            }}
        return ans;
    }
};