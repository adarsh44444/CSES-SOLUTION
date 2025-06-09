class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int maxi=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(st.top()!=-1&&heights[st.top()]>=heights[i]){
                int height=heights[st.top()];
                st.pop();
                int width=i-st.top()-1;
                int area=height*width;
                maxi=max(maxi,area);
            }
            st.push(i);
        }
        n=heights.size();
        while(st.top()!=-1){
            int height=heights[st.top()];
            st.pop();
            int width=n-st.top()-1;
            maxi=max(maxi,height*width);
        }
        return maxi;
    }
};