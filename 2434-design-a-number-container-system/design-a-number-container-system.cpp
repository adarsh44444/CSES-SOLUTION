class NumberContainers {
public:map<int,int> mp;
map<int,set<int>> mp1;
    NumberContainers() {
      /*   NumberContainers nc=new NumberContainers(); */
    }
    
    void change(int index, int number) {
        if(mp.find(index)==mp.end()){
            mp.insert({index,number});
            mp1[number].insert(index);
        }
        else{
            mp1[mp[index]].erase(index);
            mp.erase(index);
            
            mp.insert({index,number});
            mp1[number].insert(index);

        }
    }
    
    int find(int number) {
        if(mp1.find(number)!=mp1.end()){
            for(auto it:mp1[number]){
                return it;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */