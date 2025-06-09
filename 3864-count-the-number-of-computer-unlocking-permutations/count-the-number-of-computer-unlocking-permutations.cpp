class Solution {
public:
#define ll long long
int mod=1e9+7;
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        int temp=complexity[0];
        for(int i=1;i<n;i++){
            if(complexity[i]<=temp) return 0;
        }
        ll prod=1;
        for(int i=n-1;i>=1;i--){
            prod=(prod*i)%mod;
        }
        return prod;
    }
};