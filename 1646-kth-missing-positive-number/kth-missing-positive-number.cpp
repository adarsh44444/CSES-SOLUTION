class Solution {
public:
#define ll long long
    int findKthPositive(vector<int>& arr, int k) {
        ll low=0;
        ll n=arr.size();
        ll high=n-1;
        ll mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]-(1+mid)<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low+k;
    }
};