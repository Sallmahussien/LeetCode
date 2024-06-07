class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res = 0;
        stack<int> records;

        for (string op : operations) {
            if (op == \C\) {
                res -= records.top();
                records.pop();
            }
            else if (op == \D\) {
                int record = 2*records.top();
                records.push(record);
                res += record;
            } else if (op == \+\) {
                int top = records.top();
                records.pop();
                int newRecord = records.top() + top;
                records.push(top);
                records.push(newRecord);

                res += newRecord;
            } else {
                int record = stoi(op);
                records.push(record);
                res += record;
            }
        }

        return res;
        
    }
};