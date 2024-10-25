class Solution {
private:
    bool starts_with(const std::string& str, const std::string& prefix) {
        return str.size() >= prefix.size() && str.substr(0, prefix.size()) == prefix && str[prefix.size()] == '/';
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        for (string f : folder) {
            cout << f << endl;
        }

        vector<string> res;
        for (int i = 0; i < folder.size(); i++) {
            string str = folder[i];
            res.push_back(str);

            int idx = i+1;
            while (idx < folder.size() && starts_with(folder[idx], str)) {
                idx++;
            }

            i = idx-1;
        }

        return res;  
    }
};