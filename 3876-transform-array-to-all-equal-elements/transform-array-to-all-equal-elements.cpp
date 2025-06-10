class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int cnt_neg=0,cnt_pos=0;
        for(auto it:nums){
            if(it>0) cnt_pos++;
            else cnt_neg++;
        }
        if(cnt_pos%2!=0&&cnt_neg%2!=0) return false;
        vector<int> neg,pos;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) neg.push_back(i);
            else pos.push_back(i);
        }
        int cnt_1=1e9,cnt_0=1e9;
        if(pos.size()%2==0){
            cnt_1=0;
            for(int i=0;i<pos.size();i+=2){
                cout<<pos[i+1]<<" "<<pos[i]<<endl;
                cnt_1+=pos[i+1]-pos[i];
            }
        }
        if(neg.size()%2==0){
            cnt_0=0;
            for(int i=0;i<neg.size();i+=2){
                cout<<neg[i+1]<<" "<<neg[i]<<endl;
                cnt_0+=neg[i+1]-neg[i];
            }
        }
        cout<<min(cnt_1,cnt_0)<<endl;
        return min(cnt_1,cnt_0)<=k;
    }
};