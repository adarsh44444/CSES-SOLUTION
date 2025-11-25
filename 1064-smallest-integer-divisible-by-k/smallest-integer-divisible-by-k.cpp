class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long tem=0;
        long long cnt=1;
        string temp="1";
        long long num=0;
        while(cnt<=k){
            num=(num*10+1)%k;
            if(num%k==0) return cnt;
            cnt++;
            temp+="1";
        }
        return -1;
    }
};