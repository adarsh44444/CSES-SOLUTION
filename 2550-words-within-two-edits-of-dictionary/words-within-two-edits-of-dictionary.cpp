class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n=queries.size();
        int m=dictionary.size();
        for(int i=0;i<n;i++){
            string temp=queries[i];
            for(int j=0;j<m;j++){
                int cnt=0;
                string temp1=dictionary[j];
                for(int k=0;k<temp1.size();k++){
                    if(temp[k]!=temp1[k]) cnt++;
                }
                if(cnt<=2) {ans.push_back(queries[i]);break;}
            }
            
        }
        return ans;
    }
};