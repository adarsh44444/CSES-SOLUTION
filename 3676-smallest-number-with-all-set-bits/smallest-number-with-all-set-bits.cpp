class Solution {
public:
#define ll long long
    int smallestNumber(int n) {
        ll pow=1;
        while(pow<=n){
            pow*=2;
        }
        return pow-1;    
    }
};