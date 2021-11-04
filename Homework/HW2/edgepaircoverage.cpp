#include "edgecoverage.h"

int EdgeCoverage::testEdgePairCoverage(uint32_t inputNumber)
{
    int result = 0;
    if(inputNumber < 10)
    {
        for(uint32_t i = 1; i <= inputNumber; ++i)
        {
           result += i;
        }
        return result;
    }
    else
        return -1;
}
