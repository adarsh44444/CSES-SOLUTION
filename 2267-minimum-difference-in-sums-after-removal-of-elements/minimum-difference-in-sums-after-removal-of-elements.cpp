class Solution {
public:
#define ll long long
    long long minimumDifference(vector<int>& arr) {
        priority_queue<ll> pq;
        int n=arr.size();
        vector<ll> leftmin(n,-1);
        ll leftsum=0;
        for(int i=0;i<n;i++){
            leftsum+=arr[i];
            pq.push(arr[i]);
            if(pq.size()>n/3){
                leftsum-=pq.top();
                pq.pop();
            }
            if(pq.size()==n/3){
                leftmin[i]=leftsum;
            }
        }
        priority_queue<ll,vector<ll>,greater<ll>> pq1;
        vector<ll> rightmin(n,-1);
        ll rightsum=0;
        for(int i=n-1;i>=0;i--){
            rightsum+=arr[i];
            pq1.push(arr[i]);
            if(pq1.size()>n/3){
                rightsum-=pq1.top();
                pq1.pop();
            }
            if(pq1.size()==n/3){
                rightmin[i]=rightsum;
            }
        }
        ll ans=1e18;
        for(int i=0;i<n;i++){
            if(i<n-1&&leftmin[i]!=-1&&rightmin[i+1]!=-1){
                ans=min(ans,leftmin[i]-rightmin[i+1]);
            }
        }
        return ans;
    }
};