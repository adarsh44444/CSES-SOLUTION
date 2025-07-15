class LRUCache {
public:
list<int> dll;
map<int,pair<list<int>::iterator,int>> mp;
int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    /* void makerecentlyused(int key){
        if(mp.find(key)==mp.end()){
            dll.push_front(key);
            mp[key]={dll.begin(),key};
        }
        else{
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key]={dll.begin(),};
        }
    } */
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            dll.erase(mp[key].first);
            dll.push_front(key);
            int val=mp[key].second;
            mp[key]={dll.begin(),val};
        }
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        else{
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            
        }
        
        if(n<0){
            n++;
            mp.erase(dll.back());
            dll.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */