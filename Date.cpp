#include "Date.h"

Date::Date()
{
  dateMonth = 0;
  dateDay = 0;
  dateYear = 0;
}

Date::Date(int month,
           int day,
           int year)
{
  SetDate(month, day, year);
}

Date::~Date() {}

void Date::SetDate(int month,
                   int day,
                   int year)
{
  dateMonth = month;
  dateDay = day;
  dateYear = year;
}

void Date::GetDate(int &month,
                   int &day,
                   int &year) const
{
  month = dateMonth;
  day = dateDay;
  year = dateYear;
}

int Date::GetYear() const
{
  return dateYear;
}

int Date::GetMonth() const
{
  return dateMonth;
}

int Date::GetDay() const
{
  return dateDay;
}

string Date::displayDate() const
{
  ostringstream output;
  if(dateMonth < 10)
  {
    output << '0';
  }
  output << dateMonth << '/';
  if(dateDay < 10)
  {
    output << '0';
  }
  output << dateDay << '/' << dateYear;
  return output.str();
}
