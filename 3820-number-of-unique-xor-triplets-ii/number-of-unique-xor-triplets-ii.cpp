class Solution {
public:
#define ll long long
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<ll> st;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<ll> ans;
        for(auto it:st){
            for(int k=0;k<nums.size();k++){
                ans.insert(it^nums[k]);
            }
        }
        return ans.size();
    }
};