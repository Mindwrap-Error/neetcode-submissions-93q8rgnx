class MyHashMap {
public:
vector<list<pair<int, int>>> buckets;
int mod = 10007;
    MyHashMap() {
        buckets.resize(mod);
    }

    int hash(int key)
    {
        return key%mod;
    }
    
    void put(int key, int value) {
        int index = hash(key);
        for(auto& x: buckets[index])
        {
            if(x.first == key)
            {
                x.second = value;
                return;
            }
        }
        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        for(auto& x: buckets[index])
        {
            if(x.first == key)
            {
                return x.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        for(auto it = bucket.begin(); it != bucket.end(); it++)
        {
            if(it->first == key)
            {
                bucket.erase(it);
                return;
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