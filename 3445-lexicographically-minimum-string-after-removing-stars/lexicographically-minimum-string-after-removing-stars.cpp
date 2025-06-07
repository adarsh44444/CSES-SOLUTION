class Solution {
public:
    struct compare{
        bool operator()(const pair<char,int>&a, const pair<char,int> &b){
            if(a.first!=b.first) return a.first>b.first;
            else return a.second<b.second;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        int n=s.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }
            else{
                vis[i]=-1;
                if(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                vis[it.second]=-1;
            }
        }
    }
    string ans="";
    for(int i=0;i<n;i++) {/* cout<<vis[i]<<" "; */ if(vis[i]!=-1) ans+=s[i];}
    return ans;}
};