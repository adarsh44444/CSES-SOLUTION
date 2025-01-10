class Solution {
public:
#define ll long long
    int shipWithinDays(vector<int>& weights, int days) {
        ll n=weights.size();
        ll low=*max_element(weights.begin(),weights.end());
        ll high=accumulate(weights.begin(),weights.end(),0ll);
        ll mid;
        ll corr;
        while(low<=high){
            mid=(low+high)/2;
            ll temp=0;
            ll cnt=1;
            for(int i=0;i<n;i++){
                temp+=weights[i];
                if(temp>mid){
                    cnt++;
                    temp=weights[i];
                }
            }
            if(cnt<=days){
                corr=mid;
                high=mid-1;
            }
            else{
                
                low=mid+1;
            }
        }
        return corr;
    }
};