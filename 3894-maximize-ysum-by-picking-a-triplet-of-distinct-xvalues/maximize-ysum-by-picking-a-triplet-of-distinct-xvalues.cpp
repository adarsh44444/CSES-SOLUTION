class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        // CASE 1 ALL ARE SAME
        vector<pair<int,int>> vec;
        for(int i=0;i<y.size();i++){
            vec.push_back({y[i],i});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        int i=0,j=1,k=2;
        int n=y.size();
        int a=vec[i].second,b=vec[j].second,c=vec[k].second;
        if(x[a]==x[b]&&x[b]==x[c]){
            while(k<n&&x[vec[k].second]==x[vec[i].second]){
                k++;
            }
            while(j<n&&((x[vec[j].second]==x[vec[i].second])||(x[vec[j].second]==x[vec[k].second]))){
                j++;
            }
            if(j==n||k==n) return -1;
            return vec[i].first+vec[j].first+vec[k].first;
        }
        else if(x[a]==x[b]){
            while(j<n&&((x[vec[j].second]==x[vec[i].second])||(x[vec[j].second]==x[vec[k].second]))){
                j++;
            }
            if(j==n) return -1;
            return vec[i].first+vec[j].first+vec[k].first;
        }
        else if(x[a]==x[c]){
            while(k<n&&((x[vec[j].second]==x[vec[k].second])||(x[vec[i].second]==x[vec[k].second]))){
                k++;
            }
            if(k==n) return -1;
            return vec[i].first+vec[j].first+vec[k].first;
        }
        else if(x[b]==x[c]){
            while(k<n&&((x[vec[j].second]==x[vec[k].second])||(x[vec[k].second]==x[vec[i].second]))){
                k++;
            }
            if(k==n) return -1;
            return vec[i].first+vec[j].first+vec[k].first;
        }
        return vec[0].first+vec[1].first+vec[2].first;
    }
};