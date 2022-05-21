#include <iostream>
#include <string>
#include <vector>

class Date {
public:
    Date(int day, int month, int year);
    int Day() const {return day_;}
    void Day(int day);
    int Month() const {return month_;}
    void Month(int month);
    int Year() const {return year_;}
    void Year(int year);
    std::string String() const;

private:
    bool LeapYear(int year) const;
    int DaysInMonth(int month, int year) const;
    int day_{1};
    int month_{1};
    int year_{0};
};

Date::Date(int day, int month, int year) {
    Year(year);
    Month(month);
    Day(day);
}

bool Date::LeapYear(int year) const {
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}
int Date::DaysInMonth(int month, int year) const {
    if (month ==2)
        return LeapYear(year) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}
void Date::Day(int day) {
    if (day >= 1 && day <= DaysInMonth(Month(), Year())) day_ = day;
}
void Date::Month(int month) {
    if (month >= 1 && month <= 12) month_ = month;
}
void Date::Year(int year) {
    year_ = year;
}

std::string Date::String() const {
    std::string output;
    std::string month_s;
    std::string day_s = std::to_string(Day());
    std::string year_s = std::to_string(Year());

    // change the int type of month to string type
    if (Month() == 1)
        month_s = "Jan";
    else if (Month() == 2)
        month_s = "Feb";
    else if (Month() == 8)
        month_s = "Aug";
    else
        month_s = "Dec";

    output = month_s + " " + day_s + ", " + year_s;

    return output;
}

int main() {
    Date date(29, 8, 1981);
    std::cout << date.String();
    assert(date.String() == "Aug 29, 1981");
    return 0;
}
