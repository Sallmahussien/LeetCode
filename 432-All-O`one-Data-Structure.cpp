class AllOne {
private:
    unordered_map<string, int> freq_arr;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        freq_arr[key]++;
    }
    
    void dec(string key) {
        freq_arr[key]--;
        if (freq_arr[key] == 0) freq_arr.erase(key);
    }
    
    string getMaxKey() {
        if (freq_arr.size() == 0) return \\;

        int maxValue = INT_MIN;
        string max = \\;

        for (const auto& pair : freq_arr) {
            if (pair.second > maxValue) {
                maxValue = pair.second;
                max = pair.first;
            }
        }

        return max;
    }
    
    string getMinKey() {
        if (freq_arr.size() == 0) return \\;

        int minValue = INT_MAX;
        string min = \\;
        for (const auto& pair : freq_arr) {
            if (pair.second < minValue) {
                minValue = pair.second;
                min = pair.first;
            }
        }

        return min;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */