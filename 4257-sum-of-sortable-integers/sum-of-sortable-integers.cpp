class Solution {
public:
bool issorted(vector<int> &check){
    int n=check.size();
    for(int i=1;i<n;i++){
        if(check[i]>=check[i-1]){}
        else return false;
    }
    return true;
}
    int sortableIntegers(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        if(n==1||n==0) return n;
        vector<int> totaldivisor;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                totaldivisor.push_back(i);
                totaldivisor.push_back(n/i);
            }
            if(n%i==0&&n/i==i){
                totaldivisor.pop_back();
            }
        }
        for(int i=0;i<totaldivisor.size();i++){
            int div=totaldivisor[i];
            vector<int> check;
            bool flag_2=true;
            bool flag=true;
            for(int j=0;j<n;j+=(div)){
                int prev=nums[j];
                int cnt=0;
                int small=nums[j],big=nums[j];
                vector<int> temp;
                temp.push_back(nums[j]);
                for(int k=j+1;k<j+div;k++){
                    small=min(small,nums[k]);
                    big=max(big,nums[k]);
                    if(nums[k]>=prev){}
                    else{cnt++;}
                    if(cnt==2){
                        flag=false;
                    }
                    temp.push_back(nums[k]);
                    prev=nums[k];
                }
                if(!issorted(temp)&&temp[0]<temp[temp.size()-1]){
                    flag_2=false;
                    break;
                }
                if(!flag){break;}
                else{
                    check.push_back(small);
                    check.push_back(big);
                }
            }
            if(issorted(check)&&flag_2&&flag&&check.size()!=0){ 
            ans+=div;
            
        }}
        return ans;
    }
};