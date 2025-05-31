class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        unordered_set<string> vis;
        vis.insert(startGene);
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        pq.push({0,startGene});
        vector<char> check;
        check.push_back('A');
        check.push_back('C');
        check.push_back('G');
        check.push_back('T');
        while(!pq.empty()){
            int cnt=pq.top().first;
            string temp=pq.top().second;
            pq.pop();
            if(temp==endGene) return cnt;
            for(int i=0;i<temp.size();i++){
                string temp2=temp;
                for(int j=0;j<check.size();j++){
                    temp2[i]=check[j];
                    if(vis.find(temp2)==vis.end()&&st.find(temp2)!=st.end()){
                        pq.push({cnt+1,temp2});
                        vis.insert(temp2);
                    }
                }
            }
        }
        return -1;
    }
};