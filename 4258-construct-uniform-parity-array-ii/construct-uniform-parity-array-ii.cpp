class Solution {
public:
#define ll long long
    bool uniformArray(vector<int>& nums1) {
        ll even=1e12,odd=1e12;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0)even=min(even,(ll)nums1[i]);
            else odd=min(odd,(ll)nums1[i]);
        }
        bool checkodd=true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                if(nums1[i]-odd<1){checkodd=false;break;}
            }
        }
        bool checkeven=true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                if(nums1[i]-odd<1){checkeven=false;break;}
            }
        }
        cout<<checkodd<<" "<<checkodd<<endl;
        cout<<checkeven<<" "<<checkeven<<endl;
        if(checkodd||checkeven) return true;
        return false;
    }
};