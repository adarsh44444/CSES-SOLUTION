class Solution {
public:
int LCM(int a, int b)
{
    int greater = max(a, b);
    int smallest = min(a, b);
    for (int i = greater; ; i += greater) {
        if (i % smallest  == 0)
            return i;
    }
}
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n-1;i++){
            int prod=nums[i];
            int lcm=nums[i],gcd=nums[i];
            for(int j=i+1;j<n;j++){
                lcm=LCM(lcm,nums[j]);
                gcd=__gcd(nums[j],gcd);
                prod*=nums[j];
                if(prod==lcm*gcd){
                    ans=max(ans,j-i+1);
                }
                else break;
            }
        }
        return ans;
    }
};