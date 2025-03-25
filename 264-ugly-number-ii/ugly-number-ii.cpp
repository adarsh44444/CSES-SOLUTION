class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+2);
        arr[0]=1;
        arr[1]=1;
        int i2,i3,i5;
        i2=i3=i5=1;
        for(int i=2;i<=n;i++){
            int ii2=arr[i2]*2;
            int ii3=arr[i3]*3;
            int ii5=arr[i5]*5;
            int mini=min({ii2,ii3,ii5});
            arr[i]=mini;
            if(ii2==mini){
                i2++;
            }
            if(ii3==mini){
                i3++;
            }
            if(ii5==mini){
                i5++;
            }
        }
        return arr[n];
        
    }
};