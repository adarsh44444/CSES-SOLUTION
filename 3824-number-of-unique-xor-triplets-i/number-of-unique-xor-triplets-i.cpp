class Solution {
public:
#define ll long long
    int uniqueXorTriplets(vector<int>& nums) {
        ll n=nums.size();
        ll lst=0;
        if(n<=2) return n;
        for(int i=31;i>=0;i--){
            if(((1<<i)&n)>0) {lst=i; break;}
        }
        cout<<lst<<endl;
        return pow(2,lst+1);
    }
};