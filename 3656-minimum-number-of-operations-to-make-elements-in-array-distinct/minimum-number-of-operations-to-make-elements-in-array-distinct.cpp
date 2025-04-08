class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        int last=1e9;
        map<int,int> mp;
        int check=-1e9;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){last=mp[nums[i]];mp.erase(nums[i]);mp[nums[i]]=i;
            check=max(check,last);
            }
            else{mp[nums[i]]=i;}
        }
        cout<<last<<endl;

        if(check==-1e9) return 0;
        return ceil(((check+1)*1.0)/3);

    }
};