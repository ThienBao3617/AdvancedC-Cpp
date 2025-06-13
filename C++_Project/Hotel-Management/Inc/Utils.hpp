#ifndef UTILS_HPP
#define UTILS_HPP

using namespace std;

#include <string>
#include <vector>

namespace Utils {

// Split string based on delimiter, return vector<string>
vector<string> split(const string& s, char delimiter);

// Check for valid date, parse from "YYYY-MM-DD" to int year, month, day
bool parseDate(const string& dateStr, int& year, int& month, int& day);

// Calculate number of days between 2 dates (YYYY-MM-DD) – simple, assuming both are in the same year/month
int daysBetween(const string& d1, const string& d2);

// Other utility functions (e.g. trim whitespace, remove leading whitespace, etc.)
string trim(const string& str);

}

#endif 






