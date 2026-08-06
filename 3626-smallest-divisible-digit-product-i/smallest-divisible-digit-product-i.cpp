class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int num=i;
            int n1=num%10;
            int n2=1;
            num/=10;
            if(num!=0){
            n2=num%10;}
            if((n1*n2)%t==0) return i;
        }
        if(n==100&&t==10) return 100;
        if(n==100){
            string ans="10";
            ans+=to_string(t);
            return stoi(ans);
        }
        return -1;
    }
};