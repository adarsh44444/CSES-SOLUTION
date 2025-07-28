class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int ans;
        while(!q.empty()){
            string temp=q.front().first;
            int cost=q.front().second;
            q.pop();
            if(temp==endWord) return cost;
            for(int i=0;i<temp.size();i++){
                char ch=temp[i];
                for(char x='a';x<='z';x++){
                    temp[i]=x;
                    string check=temp;
                    if(st.find(check)!=st.end()){
                        q.push({check,cost+1});
                        st.erase(check);
                    }
                }
                temp[i]=ch;
            }
        }
        return 0;
    }
};