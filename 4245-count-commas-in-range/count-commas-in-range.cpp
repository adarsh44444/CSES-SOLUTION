class Solution {
public:
    int countCommas(int n) {
        string str=to_string(n);
        int m=str.size();
        if(m<4) return 0;
        if(m==4) return (n-999)*1;
        if(m==5) return 9000+(n-9999)*1;
        if(m==6) return 9000+90000+(n-99999);
        return 1e9;
    }
};