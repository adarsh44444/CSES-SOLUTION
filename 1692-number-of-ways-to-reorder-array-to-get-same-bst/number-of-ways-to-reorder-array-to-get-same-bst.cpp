class Solution {
public:
#define ll long long
const ll MOD=1e9+7;
vector<vector<ll>> pascaltree;
ll solve(vector<int> &nums){
    ll n=nums.size();
    if(n<3) return 1;
    vector<int> left_tree,right_tree;
    ll root=nums[0];
    for(ll i=1;i<n;i++){
        if(nums[i]<root) left_tree.push_back(nums[i]);
        else right_tree.push_back(nums[i]);
    }
    ll x=solve(left_tree);
    ll y=solve(right_tree);
    ll z=pascaltree[n-1][left_tree.size()];
    return (((x*y)%MOD)*z)%MOD;
}
    int numOfWays(vector<int>& nums) {
        ll n = nums.size();

        pascaltree.assign(n + 1, vector<ll>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            pascaltree[i][0] = pascaltree[i][i] = 1;

            for (int j = 1; j < i; j++) {
                pascaltree[i][j] =
                    (pascaltree[i - 1][j] +
                     pascaltree[i - 1][j - 1]) % MOD;
            }
        }
        return solve(nums)-1;
    }
};