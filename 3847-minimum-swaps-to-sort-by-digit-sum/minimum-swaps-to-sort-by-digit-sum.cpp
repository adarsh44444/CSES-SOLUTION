class Solution {
public:
#define ll long long
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        for(auto it:nums){
            ll num=it;
            ll sum=0;
            while(num!=0){
                sum+=num%10;
                num/=10;
            }
            pq.push({sum,it});
        }
        vector<int> temp;
        while(!pq.empty()){
            int num=pq.top().second;
            pq.pop();
            temp.push_back(num);
        }
        unordered_map<int,int> toidx;
        vector<int> target(n);
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            toidx[temp[i]]=i;
        }
        for(int i=0;i<n;i++){
            target[i]=toidx[nums[i]];
        }
        int cycles=0;
        for(int i=0;i<n;i++){
            if(visited[i]||target[i]==i) continue;
            int cycless=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=target[j];
                cycless++;
            }
            cycles+=cycless-1;
        }
        return cycles;
    }
};