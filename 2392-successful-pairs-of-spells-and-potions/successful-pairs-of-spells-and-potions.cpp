class Solution {
public:
#define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> anss;
        int n=spells.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            ll x=spells[i];
            ll y=success/x;
            cout<<y<<" ";
            ll ans;
            if(success%x==0){
                ll ind=lower_bound(potions.begin(),potions.end(),y)-potions.begin();
                cout<<ind<<" ";
                ans=potions.size()-ind;
            }
            else{
                ll ind=upper_bound(potions.begin(),potions.end(),y)-potions.begin();
                cout<<ind<<" ";
                ans=potions.size()-ind;
            }
            anss.push_back(ans);
        }
        return anss;
    }
};