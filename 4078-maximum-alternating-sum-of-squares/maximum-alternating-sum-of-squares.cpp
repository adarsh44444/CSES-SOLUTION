class Solution {
public:
#define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) nums[i]*=-1;
        }
        for(auto it:nums) cout<<it<<" ";
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        ll ans=0;
        while(i<j){
            ans+=nums[j]*nums[j];
            j--;
                ans-=nums[i]*nums[i];
            i++;
        }
        if(n%2!=0) ans+=nums[n/2]*nums[n/2];
        return ans;
    }
};