class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0,n=g.size(),m=s.size();
        // s[j]>=g[i]
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<n&&j<m){
            if(s[j]>=g[i]){i++;j++;}
            else j++;
        }
        return i;
    }
};