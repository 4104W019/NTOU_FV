#include "linecoverage.h"

LineCoverage::LineCoverage()
{

}

char LineCoverage::theScoreGrade(int i)
{
    if(i<0 || i>100)
        return 'X';
    else if(i>=90)
        return 'A';
    else if(i>=80)
        return 'B';
    else
        return 'C';
}
int LineCoverage::WeekName2Number(QString weekName)
{
    int n = 0;

    QString weekList[] = {"None", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (n = 0;n < 7 /* 7 is wrong !!! */; n++) {
        if (weekName == weekList[n])
            return n;
    }
    return 0;
}
