class Solution {
public:
#define ll long long
    int tupleSameProduct(vector<int>& nums) {
        map<ll,ll> prod;
        /* set<ll> st(nums.begin(),nums.end());
        vector<int> real;
        for(auto it:st){
            real.push_back(it);
        } */
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]!=nums[j]){
                    prod[nums[i]*nums[j]]++;
                }
            }
        }
        ll ans=0;
        for(auto it:prod){
            ll n=it.second;
            ans+=((n*(n-1))/2)*8;
        }
        return ans;
    }
};