class Solution {
public:
    int mirrorDistance(int n) {
     int n1=n;
     int n21=0;
     string n2="";
     while(n1!=0){
        int rem=n1%10;
        n1=n1/10;
        n2+=to_string(rem);
     }
     for(int i=0;i<n2.size();i++){
        int num=n2[i]-'0';
        n21+=num*pow(10,n2.size()-i-1);
     }
     return abs(n21-n);
    }
};