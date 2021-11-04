#ifndef EDGECOVERAGE_H
#define EDGECOVERAGE_H
#include <stdint.h>

class EdgeCoverage
{
public:
    EdgeCoverage(){}
    int testLoop(int inputNumber);
    int testEdgePairCoverage(uint32_t inputNumber);
};

#endif // EDGECOVERAGE_H
