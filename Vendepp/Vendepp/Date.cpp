#include "Date.h"

Date::Date(const unsigned int & day, const unsigned int & month, const unsigned int & year) :
	day(day), month(month), year(year)
{

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
	else if (date.getYear() == max.getYear())
	{
		if (date.getMonth() < max.getMonth())
		{
			return true;
		}
		else if (date.getMonth() == max.getMonth())
		{
			if (date.getDay() <= max.getDay())
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::afterOrSame(const Date &date)
{
	if (date.getYear() > min.getYear())
	{
		return true;
	}
	else if (date.getYear() == min.getYear())
	{
		if (date.getMonth() > min.getMonth())
		{
			return true;
		}
		else if (date.getMonth() == min.getMonth())
		{
			if (date.getDay() >= min.getDay())
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