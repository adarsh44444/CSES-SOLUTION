typedef __int128 ll;
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll num=1;
        ll n=nums.size();
        ll mask=1<<n;
        ll tot=1;
        ll temp=target;
        for(auto it:nums){
            tot*=it;
            if(it>temp*temp) return false;
        }
        if(tot!=temp*temp) return false;
        for(int i=1;i<mask-1;i++){
            ll sum=1;
            for(int j=0;j<n;j++){
                if((i&(1<<j))>0){
                    sum*=nums[j];
                    if(sum>target) break;
                }
            }
            if(sum==target) return true;
        }
        return false;
    }
};