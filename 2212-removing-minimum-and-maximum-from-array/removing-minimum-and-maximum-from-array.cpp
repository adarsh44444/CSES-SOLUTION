class Solution {
public:
#define ll long long
    int minimumDeletions(vector<int>& nums) {
        ll n=nums.size();
        ll maxi=-1e9;
        ll mini=1e9;
        ll i_max=-1,i_min=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                i_max=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                i_min=i;
            }
        }
        ll s_imax=min(i_max+1,n-i_max);
        ll s_imin=min(i_min+1,n-i_min);
        return min(min(max(i_max+1,i_min+1),max(n-i_max,n-i_min)),s_imax+s_imin);
    }
};