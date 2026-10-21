class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        sort(temp.begin(),temp.end());
        string t11=s;
        int n=s.size();
        int ans=0;
        if(n==2&&s!=temp) return -1;
        string t1,t2;
        while(s!=temp){
            if(s[0]==temp[0]){
                t1 = s.substr(1);
                sort(s.begin() + 1, s.end());
                t2 = s.substr(1);

                if (t1 != t2) ans++;
            }
            else if(s[n-1]==temp[n-1]){
                t1 = s.substr(0, n - 1);
                sort(s.begin(), s.end() - 1);
                t2 = s.substr(0, n - 1);

                if (t1 != t2) ans++;
            }
            else {
                t1 = s.substr(1);
                sort(s.begin() + 1, s.end());
                t2 = s.substr(1);

                if (t1 != t2) ans++;

                t1 = s.substr(0, n - 1);
                sort(s.begin(), s.end() - 1);
                t2 = s.substr(0, n - 1);

                if (t1 != t2) ans++;
            }
        }
        int realans=ans;
        ans=0;
        s=t11;
         while(s!=temp){
            if(s[0]==temp[0]){
                t1 = s.substr(1);
                sort(s.begin() + 1, s.end());
                t2 = s.substr(1);

                if (t1 != t2) ans++;
            }
            else if(s[n-1]==temp[n-1]){
                t1 = s.substr(0, n - 1);
                sort(s.begin(), s.end() - 1);
                t2 = s.substr(0, n - 1);

                if (t1 != t2) ans++;
            }
            else {
                t1 = s.substr(0, n - 1);
                sort(s.begin(), s.end() - 1);
                t2 = s.substr(0, n - 1);

                if (t1 != t2) ans++;

                t1 = s.substr(1);
                sort(s.begin() + 1, s.end());
                t2 = s.substr(1);

                if (t1 != t2) ans++;

            }
        }
        return min(realans,ans);
    }
};