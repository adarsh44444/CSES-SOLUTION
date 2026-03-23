class Solution {
public:
    int almostPalindromic(string s) {
        int ans=2;
        int n=s.size();
        int j,k;
        bool flag;
        for(int i=0;i<n;i++){
            // odd case wala mein left jana hai
            j=i-1,k=i+1;
             flag=true;
            while(j>=0&&k<n){
                if(s[j]!=s[k]){
                    if(flag==true){
                        flag=false;
                        j--;
                        
                    }
                    else{
                        break;
                    }                    
                }
                else{
                    ans=max(ans,k-j+1);
                    if((j>0||k<n-1)&&flag) ans=max(ans,k-j+2);
                    j--;
                    k++;
                }

            }
            j=i-1,k=i+1;
             flag=true;
            while(j>=0&&k<n){
                if(s[j]!=s[k]){
                    if(flag==true){
                        flag=false;
                        k++;
                         // here is where there is fishy
                    }
                    else{
                        break;
                    }                    
                }
                else{
                    ans=max(ans,k-j+1);
                    if((j>0||k<n-1)&&flag) ans=max(ans,k-j+2);
                    j--;
                    k++;
                }

            }
           
            j=i,k=i+1;
             flag=true;
            while(j>=0&&k<n){
                if(s[j]!=s[k]){
                    if(flag==true){
                        flag=false;
                        
                        j--;
                        
                    }
                    else{
                        break;
                    }                    
                }
                else{
                    ans=max(ans,k-j+1);
                    if((j>0||k<n-1)&&flag) ans=max(ans,k-j+2);
                    j--;
                    k++;
                }

            }
            
            j=i,k=i+1;
             flag=true;
            while(j>=0&&k<n){
                if(s[j]!=s[k]){
                    if(flag==true){
                        flag=false;
                        
                        k++;
                        
                    }
                    else{
                        break;
                    }                    
                }
                else{
                    ans=max(ans,k-j+1);
                    if((j>0||k<n-1)&&flag) ans=max(ans,k-j+2);
                    j--;
                    k++;
                }

            }
            
        }
        return ans;
    }
};