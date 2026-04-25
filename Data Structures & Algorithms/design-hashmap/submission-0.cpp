class MyHashMap {
public:
    vector<vector<pair<int,int>>>v;
    int n;
    MyHashMap() {
        n=1000001;
        v.resize(n);
    }
    
    void put(int key, int value) {
        int ind=key%n;
        for(auto &it:v[ind]){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        v[ind].push_back({key,value});
    }
    
    int get(int key) {
        int ind=key%n;
        for(auto &it:v[ind]){
            if(it.first==key){
                return it.second==-1 ? -1 : it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int ind=key%n;
        for(auto &it:v[ind]){
            if(it.first==key){
                it.second=-1;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */