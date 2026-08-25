class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto it:reservedSeats){
            mp[it[0]].insert(it[1]);
        }
        int ans=(n-mp.size())*2;
        for(auto [row,s]:mp){
            bool left=!s.count(2)&&!s.count(3)&&!s.count(4)&&!s.count(5);
            bool middle=!s.count(4)&&!s.count(5)&&!s.count(6)&&!s.count(7);
            bool right=!s.count(6)&&!s.count(7)&&!s.count(8)&&!s.count(9);
            if(left&&right) ans+=2;
            else if(left||middle||right) ans+=1;
        }
        return ans;
    }
};