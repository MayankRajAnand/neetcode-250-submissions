class MyHashSet {
public:
    vector<vector<int>>v;
    int n;
    MyHashSet() {
        n=1000001;
        v.resize(n);
    }
    
    void add(int key) {
        int ind=key%n;
        for(auto &it:v[ind]){
            if(it==key)return;
        }
        v[ind].push_back(key);
    }
    
    void remove(int key) {
        int ind=key%n;
        auto &vec=v[ind];

        for(int i=0;i<vec.size();i++){
            if(vec[i]==key){
                vec.erase(vec.begin()+i);
                return;
            }
        }

    }
    
    bool contains(int key) {
        int ind=key%n;
        for(auto &it:v[ind]){
            if(it==key)return true;
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