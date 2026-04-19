class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        while(i<n&&j<m&&nums1[i]>nums2[j]){
            i++;
            j++;
        }
        int ans=0;
        while(i<n){
            while(j<m&&nums1[i]<=nums2[j]){
                j++;
                ans=max(ans,j-i-1);
            }
            i++;
        }
        return ans;
    }
};