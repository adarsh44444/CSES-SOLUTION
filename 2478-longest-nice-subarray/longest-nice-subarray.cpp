class Solution {
public:
bool check(int mid,vector<int> &nums){
    if(mid<=1) return true;
    for(int i=0;i<=nums.size()-mid;i++){
        int bitm=0;
        bool corr=true;
        for(int j=i;j<i+mid;j++){
            if((bitm&nums[j])!=0){corr=false; break;}
            else bitm|=nums[j];
        }
        if(corr) return true;
    }
    return false;
}
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int low=1;
        int high=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,nums)){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low-1;
    }
};