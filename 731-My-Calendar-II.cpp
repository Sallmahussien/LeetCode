class MyCalendarTwo {
private:
    vector<pair<int, int>> non_overlapping;
    vector<pair<int, int>> overlapping;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (pair<int, int> event : overlapping) {
            if (! (start >= event.second || end <= event.first)) {
                return false;
            }
        }

        for (pair<int, int> event : non_overlapping) {
            if (!(start >= event.second || end <= event.first)) {
                overlapping.push_back({max(start, event.first), min(end, event.second)});
            }

        }

        non_overlapping.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */