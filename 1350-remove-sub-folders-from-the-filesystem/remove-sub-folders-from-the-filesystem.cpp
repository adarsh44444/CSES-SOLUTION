class Solution {
public:
#define ll long long
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end()); 
        int n = folder.size();
        for (int i = 0; i < n; ) {  
            string s = folder[i];
            ans.push_back(s);      
            int j = i + 1;
            while (j < n && folder[j].find(s + "/") == 0) {
                j++;
            }
            i = j;
        }
        return ans;
    }
};
