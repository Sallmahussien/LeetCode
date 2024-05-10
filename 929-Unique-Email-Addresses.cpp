class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_emails;

        for (string email: emails) {
            string str = "";
            int start_idx = 0;
            while(email[start_idx] != '@' && email[start_idx] != '+') {
                if (email[start_idx] == '.') {
                    start_idx++;
                    continue;
                }
                str += email[start_idx];
                start_idx++;
            }

            while(email[start_idx] != '@') start_idx++;

            for (int i = start_idx; i < email.size(); i++) str += email[i];

            unique_emails.insert(str);
        }

        return unique_emails.size();
    }
};