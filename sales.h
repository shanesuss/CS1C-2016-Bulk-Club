#include <QString>
#include <iomanip>
#include <iostream>
#include <string>
#include<fstream>
#include "Date.h"


using namespace std;

class Sales{
public:
    Sales();
    Sales(qString item,float cost, int quantity,Date month, Date day, Date year, int id);
    ~Sales();

    void Print();

private:


    QString sItem;
    float sCost;
    int sQuantity;
    Date sMonth;
    Date sDay;
    Date sYear;
    int sId;
]
};

#endif // SALES_H
