class Solution {
public:
#define ll long long
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int ans=stones[1]-stones[0];
        for(int i=2;i<n;i++){
            ans=max(ans,max(stones[i]-stones[i-1],stones[i]-stones[i-2]));
        }
        return ans;
    }
};