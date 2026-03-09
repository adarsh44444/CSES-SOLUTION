class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> arr(10);
        arr[0]=1;
        for(int i=1;i<10;i++){
            arr[i]=arr[i-1]*i;
        }
        long long org=n;
        long long sum=0;
        while(n!=0){
            int rem=n%10;
            n=n/10;
            cout<<rem;
            sum+=arr[rem];
        }
        string check=to_string(org);
        string real=to_string(sum);
        sort(check.begin(),check.end());
        sort(real.begin(),real.end());
        return real==check;
    }
};