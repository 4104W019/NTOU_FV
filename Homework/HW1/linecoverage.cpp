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
