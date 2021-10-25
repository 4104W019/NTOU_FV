#include "edgecoverage.h"

EdgeCoverage::EdgeCoverage()
{

}

int EdgeCoverage::testLoop(int inputNumber)
{
    int result = 0;

    if(inputNumber<0)
        return -1;
    else{
        for(int i = 0; i <= inputNumber; ++i)
        {
            result += i;
        }
        if( result % 2 == 0)
            result /= 2;
        else
            result *= 2;
    }

    return result;
}
