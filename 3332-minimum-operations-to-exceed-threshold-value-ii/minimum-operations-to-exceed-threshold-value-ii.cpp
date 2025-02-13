class Solution {
public:
    #define ll long long
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(auto it:nums){
            pq.push(it);
        }
        ll cnt=0;
        while(!pq.empty()){
            ll num1=pq.top();
            pq.pop();
            if(num1>=k) break;
            ll num2=0;
            if(!pq.empty()){
                num2=pq.top();
                pq.pop();
            }
            pq.push(min(num1,num2)*2+max(num1,num2));
            cnt++;

        }
        return cnt;

    }
};