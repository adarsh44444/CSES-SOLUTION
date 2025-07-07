class Solution {
public:
int solve(int index,int sum,vector<int> &nums,int target){
    if(index==nums.size()){
        return sum==target;
}
    int add=0,sub=0;
    add=solve(index+1,sum+nums[index],nums,target);
    sub=solve(index+1,sum-nums[index],nums,target);
    return add+sub;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);        
    }
};