class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        int n=hand.size();
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        while(!mp.empty()){
            int curr=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0) return false;
                mp[curr+i]--;
                if(mp[curr+i]==0) mp.erase(curr+i);

            }
            
        }
        return true;
    }
};