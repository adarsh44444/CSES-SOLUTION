class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low=0;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        int ans=0;
        int answer=-1;
        int n=bloomDay.size();
        while(low<=high){
            mid=(low+high)/2;
            int cnt=0;
            int ans=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                    if(cnt==k){
                        ans++;
                        cnt=0;
                    }
                }
                else{
                    cnt=0;
                }
                if(ans==m) break;
            }
            if(ans==m){
                answer=mid;
                high=mid-1;
            }
           else if(ans<m){
                low=mid+1;
            }
            
        }
        return answer;
    }
};