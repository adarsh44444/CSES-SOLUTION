class Solution {
public:
#define ll long long
    int minimumIndex(vector<int>& nums) {
        //sabse aasan tarika hai ki pehle dominant element nikal lo aur fir 
        // traverse karo array aur dhunddo kis element pe hum do pe tod sakte hai array ko
        map<ll,ll> mp;
        for(auto it:nums){
            mp[it]++;
        }
        ll num=-1;
        ll n=nums.size();
        for(auto it:mp){
            if(it.second>n/2){
                num=it.first;
            }
        }
        ll cnt=0;
        ll ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==num){
                mp[nums[i]]--;
                cnt++;
                if(cnt>(i+1)/2&&mp[num]>(n-i-1)/2){
                    return i;
                }
            }
        }
        return -1;
    }
};