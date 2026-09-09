class Solution {
public:
#define ll long long
    long long countCommas(long long n) {
        long long ans=0;
        string str=to_string(n);
        long long m=str.size();
        if(m<4) return 0;
        for(int i=4;i<m;i++){
            ll temp=pow(10,i)-pow(10,i-1);
            if(i<7) ans+=temp;
            else if(i<10) ans+=temp*2;
            else if(i<13) ans+=temp*3;
            else if(i<16) ans+=temp*4;
            else if(i<19) ans+=temp*5;
            else if(i<20) ans+=temp*6;
        }
        ll temp=n-pow(10,m-1)+1;
         if(m<7) ans+=temp;
            else if(m<10) ans+=temp*2;
            else if(m<13) ans+=temp*3;
            else if(m<16) ans+=temp*4;
            else if(m<19) ans+=temp*5;
            else if(m<22) ans+=temp*6;
            return ans;
    }
};