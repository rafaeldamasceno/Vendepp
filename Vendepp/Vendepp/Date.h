#pragma once

#include <string>

using namespace std;

class Date
{
public:
	Date();
	Date(string & input);
	Date(const unsigned int & day, const unsigned int & month, const unsigned int & year);

	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;

	void setDay(const unsigned int &day);
	void setMonth(const unsigned int &month);
	void setYear(const unsigned int &year);

	bool valid(); // checks if a date is valid, returns false if not
	bool beforeOrSame(const Date &date); // checks if a date is before or the same as another date, returns false if not
	bool afterOrSame(const Date &date); // checks if a date is after or the same as another date, returns false if not
	bool between(const Date &min, const Date &max); // checks if a date is between a certain interval (extremes included), returns false if not

	friend istream & operator >> (istream & in, Date & d);
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

bool isLeapYear(const unsigned int &year); // checks if year is leap year, returns false if not
unsigned int daysInMonth(const unsigned int &month, const unsigned int &year); // returns number of days of a month in a certain year

ostream & operator << (ostream & out, const Date & d);
istream & operator >> (istream & in, Date & d);