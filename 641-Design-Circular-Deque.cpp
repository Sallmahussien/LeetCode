class MyCircularDeque {
private:
    int size;
    int* arr;
    int added_elements;
    int front;
    int back;

public:
    MyCircularDeque(int k) : size(k), arr(new int[k]), added_elements(0), front(0), back(k - 1) {
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front - 1 + size) % size;
        arr[front] = value;
        added_elements++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;

        back = (back + 1) % size;
        arr[back] = value;
        added_elements++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % size;
        added_elements--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        back = (back - 1 + size) % size;
        added_elements--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];        
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        return added_elements == 0; 
    }
    
    bool isFull() {
        return added_elements == size;
    }
};


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */