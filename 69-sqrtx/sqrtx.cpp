class Solution {
public:
#define ll long long
    int mySqrt(int x) {
        ll low=1,high=x;
        ll ans;
        while(low<=high){
            ll mid=(low+high)/2;
            if(mid*mid==x) {ans=mid;break;}
            if(mid*mid<=x) {ans=mid;low=mid+1;}
            else {high=mid-1;}
        }
        return ans;
    }
};