class Solution {
public:
#define ll long long
    int splitArray(vector<int>& nums, int k) {
        ll n=nums.size();
        ll mid;
        ll low=*max_element(nums.begin(),nums.end());
        ll high=accumulate(nums.begin(),nums.end(),0ll);
        while(low<=high){
            mid=(low+high)/2;
            ll cnt=1;
            ll temp=0;
            for(int i=0;i<n;i++){
                if(temp+nums[i]>mid){
                    cnt++;
                    temp=0;
                }
                temp+=nums[i];
            }
            if(cnt>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};