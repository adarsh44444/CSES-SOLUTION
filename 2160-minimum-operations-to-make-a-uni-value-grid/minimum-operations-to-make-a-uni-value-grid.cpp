class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> check;
        for(auto it:grid){
            for(auto ti:it){
                check.push_back(ti);
            }
        }
        int n=check.size();
        sort(check.begin(),check.end());
        for(int i=0;i<n;i++){
            if((check[0]-check[i])%x!=0) return -1;
        }
        int ans=1e9;
        
        int mid=(0+n)/2;
        // check karo mid ke liye
        // phir check karna mid +1 ke liye 
        //phir check karna mid-1 ke liye;
        int temp=check[mid];
        int sum=0;
        for(int i=0;i<n;i++){
             sum+=abs(check[i]-temp)/x;
        }
        ans=min(ans,sum);
        if(mid+1<n){
        temp=check[mid+1];}
        sum=0;
        for(int i=0;i<n;i++){
             sum+=abs(check[i]-temp)/x;
        }
        ans=min(ans,sum);
        if(mid-1>=0){
        temp=check[mid-1];}
        sum=0;
        for(int i=0;i<n;i++){
             sum+=abs(check[i]-temp)/x;
        }
        ans=min(ans,sum);
        return ans;

    }
};