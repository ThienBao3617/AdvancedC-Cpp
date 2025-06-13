#include "Utils.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <ctime>

using namespace std;

namespace Utils {

    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    string trim(const string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == string::npos) return "";
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }

    bool parseDate(const string& dateStr, int& year, int& month, int& day) {
        // expect dateStr = "YYYY-MM-DD"
        if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-') return false;
        try {
            year = stoi(dateStr.substr(0,4));
            month = stoi(dateStr.substr(5,2));
            day = stoi(dateStr.substr(8,2));
        } catch (...) {
            return false;
        }
        return true;
    }

    int daysBetween(const string& d1, const string& d2) {
        // simple way using struct tm and difftime
        int y1, m1, day1;
        int y2, m2, day2;
        if (!parseDate(d1, y1, m1, day1) || !parseDate(d2, y2, m2, day2)) {
            return 0;
        }
        tm tm1 = {};
        tm1.tm_year = y1 - 1900;
        tm1.tm_mon = m1 - 1;
        tm1.tm_mday = day1;
        tm1.tm_hour = 0;
        tm1.tm_min = 0;
        tm1.tm_sec = 0;
        tm tm2 = {};
        tm2.tm_year = y2 - 1900;
        tm2.tm_mon = m2 - 1;
        tm2.tm_mday = day2;
        tm2.tm_hour = 0;
        tm2.tm_min = 0;
        tm2.tm_sec = 0;
        time_t time1 = mktime(&tm1);
        time_t time2 = mktime(&tm2);
        if (time1 == -1 || time2 == -1) return 0;
        double diff = difftime(time2, time1);
        int days = static_cast<int>(diff / (60*60*24));
        return days;
    }
} 
