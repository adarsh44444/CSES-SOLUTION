class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto it:nums){
            mp[it]=cnt++;
            temp.push_back(it);
        }
        sort(temp.begin(), temp.end(), [](int a, int b) {
    int num1 = a, num2 = b;
    int digit_sum1 = 0, digit_sum2 = 0;

    while (num1 != 0) {
        digit_sum1 += num1 % 10;
        num1 /= 10;
    }

    while (num2 != 0) {
        digit_sum2 += num2 % 10;
        num2 /= 10;
    }

    if (digit_sum1 != digit_sum2)
        return digit_sum1 < digit_sum2;

    return a < b;
});
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=temp[i]){
                ans++;
                int act_idx=mp[temp[i]];
                int t=nums[i];
                nums[act_idx]=t;
                mp[t]=act_idx;
                mp[temp[i]]=i;
            }
        }
        return ans;
    }
};