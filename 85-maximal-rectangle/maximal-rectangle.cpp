class Solution {
public:
    int histogram(vector<int>& heights){
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1&&heights[i]<=heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width=i-st.top()-1;
                int area=height*width;
                maxi=max(area,maxi);
            }
            st.push(i);
        }
        while(st.top()!=-1){
            int height=heights[st.top()];
            st.pop();
            int width=heights.size()-st.top()-1;
            int area=height*width;
            maxi=max(area,maxi);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> heightts(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(matrix[0][j]=='1') heightts[0][j]++;
        }
        int ans=0;
        ans=max(ans,histogram(heightts[0]));
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') heightts[i][j]=0;
                else heightts[i][j]=heightts[i-1][j]+1;
            }
            ans=max(ans,histogram(heightts[i]));
        }
        return ans;
    }
};