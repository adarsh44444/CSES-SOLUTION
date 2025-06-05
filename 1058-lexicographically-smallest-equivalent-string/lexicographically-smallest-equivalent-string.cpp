class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,set<char>> mp;
        int n=s1.size();
        for(int i=0;i<n;i++){
        mp[s1[i]].insert(s2[i]);
        mp[s2[i]].insert(s1[i]);
        }
        for(int i=0;i<n;i++){
            queue<char> q;
            q.push(s2[i]);
            while(!q.empty()){
                char ch=q.front();
                q.pop();
                for(auto it:mp[ch]){
                if(mp[s1[i]].find(it)==mp[s1[i]].end()){
                    q.push(it);
                    mp[s1[i]].insert(it);
                }
            }
        }
        queue<char> q1;
            q1.push(s1[i]);
            while(!q1.empty()){
                char ch=q1.front();
                q1.pop();
                for(auto it:mp[ch]){
                if(mp[s2[i]].find(it)==mp[s2[i]].end()){
                    q1.push(it);
                    mp[s2[i]].insert(it);
                }
            }
        }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<endl;
            for(auto ti:it.second){
                cout<<ti<<" ";
            }
            cout<<endl;
        }
        string ans="";
        int m=baseStr.size();
        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            if(mp.find(ch)==mp.end()) ans+=baseStr[i];
            else ans+=*mp[ch].begin();
        }
        return ans;

    }
};