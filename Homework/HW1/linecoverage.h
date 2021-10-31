#ifndef LINECOVERAGE_H
#define LINECOVERAGE_H
#include <stdint.h>

class LineCoverage
{
public:
    LineCoverage();

    /**
     * @brief thePartialSums
     *  Used to be an unit test API.
     * @param inputNumber [IN]: the score
     * @return thePartialSums, if(inputNumber>10) return -1;
     *                          else return inputNumber(inputNumber+1)/2 >1
     */
    int thePartialSums(uint32_t inputNumber);
};

#endif // LINECOVERAGE_H
