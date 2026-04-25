class MyHashSet {
public:
    vector<vector<pair<int,int>>>v;
    int n;
    MyHashSet() {
        n=1000001;
        v.resize(n);
    }
    
    void add(int key) {
        int ind=key%n;

        for(auto &it:v[ind]){
            if(it.first==key){
                it.second=1;
                return;
            }
        }
        v[ind].push_back({key,1});
    }
    
    void remove(int key) {
        int ind=key%n;

        for(auto &it:v[ind]){
            if(it.first==key){
                it.second=-1;
                return;
            }
        }
    }
    
    bool contains(int key) {
        int ind=key%n;
        for(auto it:v[ind]){
            if(it.first==key and it.second==1){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */