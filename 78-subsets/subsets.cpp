class Solution {
public:
#define ll long long
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        ll mask=1<<n;
        vector<vector<int>> ans;
        for(int i=0;i<mask;i++){
            ll num=i;
            vector<int> temp;
            for(int j=0;j<n;j++){
                if((num&(1<<j))>0){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};