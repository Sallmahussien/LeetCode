class Solution {
private:
    int countDays(string date) {
        unordered_map<string, int> mappedDate = mapDate(date);
        int year = mappedDate["year"];
        int month = mappedDate["month"];
        int day = mappedDate["day"];
        int days = 0;

        for (int i = 1900; i < year; i++) {
            days += isLeapYear(i) ? 366 : 365;
        }

        unordered_map<int, int> daysInMonth = getDaysInMonth(year);

        for (int i = 1; i < month; i++) {
            days += daysInMonth[i];
        }

        days += day;

        return days;
    }

    unordered_map<string, int> mapDate(string date) {
        unordered_map<string, int> res;

        res["year"] = stoi(date.substr(0, 4));
        res["month"] = stoi(date.substr(5, 2));
        res["day"] = stoi(date.substr(8, 2));

        return res;
    }

    bool isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    unordered_map<int, int> getDaysInMonth(int year) {
        unordered_map<int, int> daysInMonth;
        daysInMonth[1] = 31;
        daysInMonth[2] = isLeapYear(year) ? 29 : 28;
        daysInMonth[3] = 31;
        daysInMonth[4] = 30;
        daysInMonth[5] = 31;
        daysInMonth[6] = 30;
        daysInMonth[7] = 31;
        daysInMonth[8] = 31;
        daysInMonth[9] = 30;
        daysInMonth[10] = 31;
        daysInMonth[11] = 30;
        daysInMonth[12] = 31;

        return daysInMonth;
    }


public:
    int daysBetweenDates(string date1, string date2) {
        return abs(countDays(date1) - countDays(date2));
    }
};