class Solution {
public:
    int maxDistance(string s, int k) {
        //sirf ek hi direction mein jana hau
        // for north
        int temp=k;
        int x=0,y=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(temp>0&&s[i]=='S'){
                y++;
                temp--;
            }
            else if(temp>0&&s[i]=='W'){
                x++;
                temp--;
            }
            else{
                if(s[i]=='N') y++;
                if(s[i]=='E') x++;
                if(s[i]=='W') x--;
                if(s[i]=='S') y--;
            }
            ans=max(ans,abs(x)+abs(y));
        }
        temp=k;
        x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(temp>0&&s[i]=='E'){
                x--;
                temp--;
            }
            else if(temp>0&&s[i]=='S'){
                y++;
                temp--;
            }
            else{
                if(s[i]=='N') y++;
                if(s[i]=='E') x++;
                if(s[i]=='W') x--;
                if(s[i]=='S') y--;
            }
            ans=max(ans,abs(x)+abs(y));
        }
        temp=k;
        x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(temp>0&&s[i]=='N'){
                y--;
                temp--;
            }
            else if(temp>0&&s[i]=='E'){
                x--;
                temp--;
            }
            else{
                if(s[i]=='N') y++;
                if(s[i]=='E') x++;
                if(s[i]=='W') x--;
                if(s[i]=='S') y--;
            }
            ans=max(ans,abs(x)+abs(y));
        }
        temp=k;
        x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(temp>0&&s[i]=='W'){
                x++;
                temp--;
            }
            else if(temp>0&&s[i]=='N'){
                y--;
                temp--;
            }
            else{
                if(s[i]=='N') y++;
                if(s[i]=='E') x++;
                if(s[i]=='W') x--;
                if(s[i]=='S') y--;
            }
            ans=max(ans,abs(x)+abs(y));
        }
        return ans;

    }
};