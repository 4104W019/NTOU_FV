#include "linecoverage.h"

int LineCoverage::thePartialSums(uint32_t inputNumber)
{
    int result = 0;
    if(inputNumber > 10)
        result = -1;
    else{
        for(uint32_t i = 1; i <= inputNumber; ++i)
            result += i;
    }
    return result;
}
