#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

class Date
{
public:
  Date();
  Date(int month,
       int day,
       int year);
  ~Date();
  void SetDate(int month,
               int day,
               int year);
  void GetDate(int &month,
               int &day,
               int &year) const;
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;
  string DisplayDate() const;

private:
  int dateMonth;
  int dateDay;
  int dateYear;
);

#endif /* DATE_H_ */
