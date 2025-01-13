class Solution {
public:
    int minimumLength(string s) {
        vector<int> ans(100,0);
        for(int i=0;i<s.size();i++){
            ans[s[i]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(ans[s[i]-'a']>2){
                ans[s[i]-'a']-=2;
            }
        }
        for(int i=27;i<100;i++){
            ans[i]+=i;
        }
        for(int i=0;i<27;i++){
            cnt+=ans[i];
        }
        return cnt;
    }
};