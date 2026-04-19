class Solution {
public:
#define ll long long
ll memo[17][11][2];
ll onpath[16];
string s;
ll dp(ll i,ll v,bool t){
    if(i==16) return 1;
    if(memo[i][v][t]!=-1) return memo[i][v][t];
    ll limit=t==1?s[i]-'0':9;
    ll result=0;
    for(int x=0;x<=limit;x++){
        if(onpath[i]){
            if(x>=v){
                result+=dp(i+1,x,t&&(x==limit));
            }
        }
        else{
            result+=dp(i+1,v,t&&(x==limit));
        }
    }
    return memo[i][v][t]=result;
}
ll solve(ll n){
     if (n < 0) return 0;
 s=to_string(n);
    while(s.size()<16){
        s="0"+s;
    }
    memset(memo,-1,sizeof(memo));
    return dp(0,0,true);
}
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        int i=0;
        memset(onpath, 0, sizeof(onpath));
        onpath[i]=true;
        for(auto it:directions){
            if(it=='D') i+=4;
            else i+=1;
            onpath[i]=true;
        }
        return solve(r)-solve(l-1);
    }
};