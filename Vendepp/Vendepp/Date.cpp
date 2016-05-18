#include<sstream>

#include "Date.h"

Date::Date(const unsigned int & day, const unsigned int & month, const unsigned int & year) :
	day(day), month(month), year(year)
{

}

Date::Date()
{

}

Date::Date(string & input)
{
	readDate(input);
}

unsigned int Date::getDay() const
{
	return day;
}

unsigned int Date::getMonth() const
{
	return month;
}

unsigned int Date::getYear() const
{
	return year;
}

void Date::setDay(const unsigned int &day)
{
	this->day = day;
}

void Date::setMonth(const unsigned int &month)
{
	this->month = month;
}

void Date::setYear(const unsigned int &year)
{
	this->year = year;
}

string Date::writeDate() const
{
	stringstream date;
	date << day << "/" << month << "/" << year;
	return date.str();
}

Date Date::readDate(const string & prompt) {
	string sday, smonth, syear;
	stringstream promptstream;
	promptstream.str(prompt);
	getline(promptstream, sday, '/');
	promptstream.ignore();
	getline(promptstream, smonth, '/');
	promptstream.ignore();
	getline(promptstream, syear);
	return (Date(stoi(sday), stoi(smonth), stoi(syear)));
}

bool isLeapYear(const unsigned int &year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int daysInMonth(const unsigned int &month, const unsigned int &year)
{
	if ((month % 2 == 1 && month <= 7) || (month % 2 == 0 && month >= 8))
	{
		return 31;
	}
	else if (month == 2)
	{
		if (isLeapYear(year))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else
	{
		return 30;
	}
}

bool Date::valid()
{
	if (month >= 1 && month <= 12)
	{
		if (day >= 1 && day <= daysInMonth(month, year))
		{
			return true;
		}
	}
	return false;
}

bool Date::beforeOrSame(const Date &date)
{
	if (year < date.getYear())
	{
		return true;
	}
	else if (year == date.getYear())
	{
		if (month < date.getMonth())
		{
			return true;
		}
		else if (month == date.getMonth())
		{
			if (day <= date.getDay())
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::afterOrSame(const Date &date)
{
	if (year > date.getYear())
	{
		return true;
	}
	else if (year == date.getYear())
	{
		if (month > date.getMonth())
		{
			return true;
		}
		else if (month == date.getMonth())
		{
			if (day >= date.getDay())
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::between(const Date &min, const Date &max)
{
	if (afterOrSame(min) && beforeOrSame(max))
	{
		return true;
	}
	else
	{
		return false;
	}
}