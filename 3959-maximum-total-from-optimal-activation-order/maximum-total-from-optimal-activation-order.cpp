class Solution {
public:
#define ll long long
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        vector<pair<ll,ll>> vec;
        for(int i=0;i<value.size();i++){
            vec.push_back({limit[i],value[i]});
        }
        sort(vec.begin(),vec.end(),[](const pair<ll,ll> &a,const pair<ll,ll> &b){
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        });
        /* for(auto it:vec){
            cout<<it.first<<" "<<it.second<<endl;
        } */
        int i=0;
        int j=0;
        int cnt=0;
        ll ans=0;
        while(i<vec.size()){
            if(cnt<vec[i].first){
                ans+=vec[i].second;
                i++;
                cnt++;
            }
            while(j<vec.size()){
                if(vec[j].first<=cnt){j++;}
                else break;
            }
            cnt=i-j;
            if(j>=i){
                cnt=0;
                i=j;
            }
            if(j==vec.size()) break;
        }
        return ans;

    }
};