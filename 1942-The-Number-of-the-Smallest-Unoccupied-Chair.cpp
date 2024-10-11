class Solution {
private:
    static bool compare(tuple<string, int, int> a, tuple<string, int, int> b) {
        if (get<1>(a) == get<1>(b)) {
            // arrival == departure
            return get<0>(a) == "departure" && get<0>(b) == "arrival";
        }

        return get<1>(a) < get<1>(b);
    }

public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<tuple<string, int, int>> events; // type, time, index

        for (int i = 0; i < times.size(); i++) {
            events.push_back({"arrival", times[i][0], i});
            events.push_back({"departure", times[i][1], i});
        }

        sort(events.begin(), events.end(), compare);

        priority_queue <int, vector<int>, greater<int>> chairs;
        for (int i = 0; i < times.size(); i++) {
            chairs.push(i); // Initially, all chairs are available (0 to n-1)
        }

        unordered_map<int, int> idx_to_chair;
        int res = -1;

        for (auto event : events) {
            string type = get<0>(event);
            int time = get<1>(event);
            int idx = get<2>(event);

            if (type == "arrival") {
                int chair = chairs.top();
                chairs.pop();
                idx_to_chair[idx] = chair;

                if (idx == targetFriend) {
                    res = chair;
                    break;
                }

            } else if (type == "departure") {
                chairs.push(idx_to_chair[idx]);
                idx_to_chair.erase(idx);
            }
        }

        return res;
    }
};