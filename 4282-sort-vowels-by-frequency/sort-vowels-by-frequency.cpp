class Solution {
public:
bool isvowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
    return false;
}
    string sortVowels(string s) {
        string ans="";
        map<char,int> first,freq;
        vector<pair<int,pair<char,int>>> vec;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
            freq[s[i]]++;
            if(first.find(s[i])==first.end()){
                first[s[i]]=i;
            }
            }
        }
        if(freq.size()==0) return s;
        for(char ch='a';ch<='z';ch++){
            if(first.find(ch)!=first.end()){
            vec.push_back({freq[ch],{ch,first[ch]}});}
        }
        sort(vec.begin(),vec.end(),[](auto &a,auto &b){
            if(a.first!=b.first) return a.first>b.first;
            return a.second.second<b.second.second;
        });
        int j=0;
        for(int i=0;i<s.size();i++){
            cout<<vec[j].second.first<<" ";
            if(isvowel(s[i])&&j<vec.size()){
                if(vec[j].first==0) j++;
                ans+=vec[j].second.first;
                vec[j].first=vec[j].first-1;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};