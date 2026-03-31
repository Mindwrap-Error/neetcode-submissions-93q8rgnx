class MyHashSet {
public:
vector<int> hash;
    MyHashSet() {
    }
    
    void add(int key) {
        bool found = false;
        for(auto x: hash)
        {
            if(x == key)
            {
                found = true;
            }
        }
        if(!found)
        {
            hash.push_back(key);
        }
    }
    
    void remove(int key) {
        vector<int> tmp;
        for(auto x: hash)
        {
            if(x != key)
            {
                tmp.push_back(x);
            }
        }
        hash = tmp;
    }
    
    bool contains(int key) {
        for(auto x: hash)
        {
            if(x == key)
            {
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