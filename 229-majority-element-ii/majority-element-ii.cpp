class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int cnt1=0,cnt2=0,el1=-1e9,el2=-1e9;
        for(int i=0;i<n;i++){
            if(cnt1==0&&nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0&&nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int cnt11=0,cnt22=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]) cnt11++;
            if(el2==nums[i]) cnt22++;
        }
        if(cnt11>n/3) ans.push_back(el1);
        if(cnt22>n/3) ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};