class Solution {
public:
bool solve(int mid,vector<int>& bloomDay,int m,int k){
    int cnt=0;
    int ans=0;
    int n=bloomDay.size();
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=mid){
            cnt++;
        }
        else{
            ans+=cnt/k;
            cnt=0;
        }
    }
    ans+=cnt/k;
    cout<<ans<<endl;
    return ans>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        int low=*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,bloomDay,m,k)) {ans=mid; high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
};