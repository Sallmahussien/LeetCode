class CustomStack {
private:
    int size;
    int* arr;
    int idx;
public:
    CustomStack(int maxSize): size(maxSize), arr(new int[size]), idx(-1) {
        
    }
    
    void push(int x) {
        if (idx + 1 == size) return;

        arr[++idx] = x;
    }
    
    int pop() {
        if (idx == -1) return -1;

        return arr[idx--];
    }
    
    void increment(int k, int val) {
        if (idx == -1) return;

        for (int i = 0; k && i < size; i++) {
            arr[i] += val;
            k--;
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */