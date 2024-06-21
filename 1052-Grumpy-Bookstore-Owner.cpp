class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int statisfiedCustomers = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (!grumpy[i]) statisfiedCustomers += customers[i];
        }

        int additionalCustomers = 0, currWindow = 0;
        int count = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i]) currWindow += customers[i];
            count++;

            if (count == minutes) {
                count--;
                additionalCustomers = max(additionalCustomers, currWindow);
                if (grumpy[i+1-minutes]) currWindow -= customers[i+1-minutes];
            }
        }

        return statisfiedCustomers + additionalCustomers;
    }
};