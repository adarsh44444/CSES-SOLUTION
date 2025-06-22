class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int,int>> temp;
        for(auto it:buildings){
            temp.push_back({it[0], it[1]});
        }

        // sort by y (2nd)
        sort(temp.begin(), temp.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second < b.second;
        });

        vector<vector<int>> xadj(100001);  // xadj[y]
        for(auto it : temp){
            xadj[it.second].push_back(it.first);  // store x for same y
        }

        // sort by x (1st)
        sort(temp.begin(), temp.end());

        vector<vector<int>> yadj(100001);  // yadj[x]
        for(auto it : temp){
            yadj[it.first].push_back(it.second);  // store y for same x
        }

        // \U0001f525 sort all rows to make .front() and .back() valid
        for(int i = 0; i <= 100000; ++i){
            sort(xadj[i].begin(), xadj[i].end());
            sort(yadj[i].begin(), yadj[i].end());
        } 

        int ans = 0;
        for(auto it : buildings){
            int x1 = it[0];
            int y1 = it[1];

            if(xadj[y1].front() < x1 && xadj[y1].back() > x1 &&
               yadj[x1].front() < y1 && yadj[x1].back() > y1){
                ans++;
            }
        }

        return ans;
    }
};
