class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> answer;
        int j=0;
        int cnt=0;
        int n=A.size();
        set<int> st1,st2;
        while(j<n){
            if(A[j]==B[j]){
                j++;
                cnt++;
            }
            else{
            st1.insert(A[j]);
            st2.insert(B[j]);
            if(st1.find(B[j])!=st1.end()){
                st1.erase(B[j]);
                cnt++;
            }
            if(st2.find(A[j])!=st2.end()){
                cnt++;
                st2.erase(A[j]);
            }
            j++;}
            answer.push_back(cnt);
        }
        return answer;
    }
};