class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool f1=true,f2=false;
        int f1_s=0,f2_s=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                f1=!f1;
                f2=!f2;
            }
            if((i+1)%6==0){
                f1=!f1;
                f2=!f2;
            }
            if(f1){
                f1_s+=nums[i];
            }
            else{
                f2_s+=nums[i];
            }
        }
        return f1_s-f2_s;
    }
};