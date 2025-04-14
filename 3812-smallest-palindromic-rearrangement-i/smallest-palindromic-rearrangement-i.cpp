class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string temp=s.substr(0,n/2);
        sort(temp.begin(),temp.end());
        string ans="";
        ans+=temp;
        if(n%2!=0){
            ans+=s[n/2];
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};