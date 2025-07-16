class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxi=1;
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i, r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(maxi<r-l+1){
                    maxi=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(maxi<r-l+1){
                    maxi=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxi);
    }
};