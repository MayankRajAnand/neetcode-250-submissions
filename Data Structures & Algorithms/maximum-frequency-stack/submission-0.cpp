class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,int>m;
    int pos=0;

    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        pos++;
        pq.push({m[val],{pos,val}});
    }
    
    int pop() {
        auto it=pq.top();
        pq.pop();

        m[it.second.second]--;

        return it.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */