class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> max_heap;

        if (a) max_heap.push({a, 'a'});
        if (b) max_heap.push({b, 'b'});
        if (c)  max_heap.push({c, 'c'});

        string res = "";

        while (!max_heap.empty()) {
            pair<int, char> top = max_heap.top();
            char char_to_add = top.second;
            max_heap.pop();

            int n = res.size();
            if (n >= 2 && res[n-1] == char_to_add && res[n-2] == char_to_add) {
                // gets the next max
                if (max_heap.empty()) break;

                pair<int, char> second_top = max_heap.top();
                max_heap.pop();

                res += second_top.second;
                second_top.first--;

                if (second_top.first > 0) max_heap.push(second_top);
            } else  {
                res += char_to_add;
                top.first--;
            }

            if (top.first != 0) max_heap.push(top);
        }

        return res;
    }
};