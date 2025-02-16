class Solution {
public:
bool solve(int index,int n,vector<int> &seq,vector<bool> &used){
    if(index==seq.size()) return true;
    if(seq[index]!=0) return solve(index+1,n,seq,used);
    for(int i=n;i>=1;i--){
        int nextindex=(i==1)?index:index+i;
        if(used[i]||(i>1&&(nextindex>=seq.size()||seq[nextindex]!=0))){continue;}
        seq[index]=seq[nextindex]=i;
        used[i]=true;
        if(solve(index+1,n,seq,used)) return true;
        used[i]=false;
        seq[index]=seq[nextindex]=0;
    }
    return false;
}
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2*n-1);
        vector<bool> used(n,false);
        bool val=solve(0,n,seq,used);
        return seq;
    }
};