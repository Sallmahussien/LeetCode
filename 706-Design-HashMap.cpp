class MyHashMap {
private:
    vector<int> keys;
    vector<int> values;

    int get_idx(int key) {
        int idx = -1;
        for (int i = 0; i < keys.size(); i++) {
            if (key == keys[i]) {
                idx = i;
                break;
            }
        }

        return idx;
    }

public:
    MyHashMap() {
    
    }
    
    void put(int key, int value) {
        int idx = get_idx(key);

        if (idx == -1) {
            keys.push_back(key);
            values.push_back(value);
        } else {
            values[idx] = value;
        }
        
    }
    
    int get(int key) {
        int idx = get_idx(key);

        return idx == -1 ? idx : values[idx];
    }
    
    void remove(int key) {
        int idx = get_idx(key);

        if (idx != -1) {
            int last_idx = keys.size() - 1;

            swap(keys[idx], keys[last_idx]);
            swap(values[idx], values[last_idx]);

            keys.pop_back();
            values.pop_back();
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