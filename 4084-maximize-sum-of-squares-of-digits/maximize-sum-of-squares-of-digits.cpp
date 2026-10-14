class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(num>0){
            if(num==1&&sum>=10) return "";
            else if(sum<10){
                ans+=to_string(sum);
                sum=0;
            }
            else{
                ans+='9';
                sum-=9;
            }
            num--;
        }
        return ans;
    }
};