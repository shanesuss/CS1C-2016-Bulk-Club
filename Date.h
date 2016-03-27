#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

class Date
{
public:
  //Default Constructor
  Date();

  //Non-default Constructor
  Date(int month,
       int day,
       int year);

  //Default Destructor
  ~Date();

  //MUTATORS
  void SetDate(int month,
               int day,
               int year);

  //ACCESSORS
  void GetDate(int &month,
               int &day,
               int &year) const;

  int GetYear() const;

  int GetMonth() const;

  int GetDay() const;

  string DisplayDate() const;

  //OVERLOADED OPERATORS
  bool operator<(Date compareto) const;

  bool operator>(Date compareto) const;

private:
  int dateMonth;
  int dateDay;
  int dateYear;
};

#endif /* DATE_H_ */
