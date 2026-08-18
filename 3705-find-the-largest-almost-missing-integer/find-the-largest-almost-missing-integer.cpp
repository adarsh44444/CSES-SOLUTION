class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pref(n,0);
        pref[0]=1;
        if(k<n)pref[k]-=1;
        else return *max_element(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(i+k-1<n){
                pref[i]=pref[i]+pref[i-1]+1;
                if(i+k<n) pref[i+k]-=1;
            }
            else{
                pref[i]=pref[i]+pref[i-1];
            }
            cout<<pref[i]<<" ";
        }
        map<int,int> mp;
        for(auto i=0;i<n;i++){
                mp[nums[i]]+=pref[i];
        }
        int ans=-1;
        for(auto it:mp){
            if(it.second==1) ans=max(ans,it.first);
        }
        return ans;
    }
};