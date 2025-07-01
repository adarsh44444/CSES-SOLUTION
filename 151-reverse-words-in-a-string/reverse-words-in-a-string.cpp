class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        int i = 0, n = s.size();
        
        while (i < n) {
            while (i < n && s[i] == ' ') i++; // skip spaces
            if (i >= n) break;
            
            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            vec.push_back(temp);
        }

        reverse(vec.begin(), vec.end());

        string result = "";
        for (int j = 0; j < vec.size(); ++j) {
            result += vec[j];
            if (j != vec.size() - 1) result += " ";
        }

        return result;
    }
};
