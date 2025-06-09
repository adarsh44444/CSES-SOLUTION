class Solution {
public:
int dp[101][101];
int minoper(int i,int j,string& word1,string& word2,int n,bool isreversed){
    int cnt=0;
    if(isreversed==1) cnt++;
    int idx=i,jdx=i,mul=1;
    if(isreversed==1) jdx=j;
    if(isreversed==1) mul=-1;
    int freq[26][26]={0};
    for(int k=i;k<=j;k++){
        if(word1[k]==word2[jdx]){

        }
        else if(word1[k]!=word2[jdx]){
            char wanted=word2[jdx];
            char got=word1[k];
            if(freq[got-'a'][wanted-'a']>0){
                freq[got-'a'][wanted-'a']--;
            }
            else{
                cnt++;
                freq[wanted-'a'][got-'a']++;
            }
        }
        jdx=jdx+mul*1;
    }
    return cnt;
}
    int solve(int i,int j,string& word1,string& word2,int n){
        if(i>=n) return 0;
        if(j>=n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int continu=0,start=0;
        continu=solve(i,j+1,word1,word2,n);
        start=min(minoper(i,j,word1,word2,n,true),minoper(i,j,word1,word2,n,false))+solve(j+1,j+1,word1,word2,n);
        return dp[i][j]=min(start,continu);
    }
    int minOperations(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2,word1.size());
    }
};