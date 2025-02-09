class Solution {
public:
#define ll long long
    long long countBadPairs(vector<int>& nums) {
        ll n=nums.size();
        map<ll,ll> mp;
        for(int i=0;i<n;i++){
            nums[i]-=i;
            mp[nums[i]]++;
        }
        ll temp=0;
        ll res=(n*(n-1))/2;
        for(auto it:mp){
            ll n1=it.second;
            temp+=(n1*(n1-1))/2;
        }
        return res-temp;
    }
};