class Solution {
public:
double solve(double x,int n){
    if(n==0) return 1;
    if(x==0) return 0;
    double res=solve(x,n/2);
    res=res*res;
    return (n&1)?res*x:res;
}
    double myPow(double x, int n) {
        double ans=solve(x,n);
        return (n>=0)?ans:1/ans;
    }
};