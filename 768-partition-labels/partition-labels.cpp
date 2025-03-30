class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        int i=0,j=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int start=i;
            int end=mp[s[i]];
            for(int k=start;k<=end;k++){
                if(end<=mp[s[k]]){
                    end=mp[s[k]];
                }
            }
            ans.push_back(end-start+1);
            i=end;
        }
        return ans;
    }
};