class Solution {
public:
vector<int> left(vector<int> &nums){
    int n=nums.size();
    vector<int> res(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()&&nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}
vector<int> right(vector<int> &nums){
    int n=nums.size();
    vector<int> res(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}
    int minOperations(vector<int>& nums) {
        vector<int> left1=left(nums);
        vector<int> right1=right(nums);
        int n=nums.size();
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++){
            /* cout<<left1[i]<<" "<<right1[i]<<" "<<endl; */
            if(mp.find({left1[i],right1[i]})==mp.end()&&nums[i]!=0){
                mp[{left1[i],right1[i]}]=1;
            }
        }
        return mp.size();
    }
};