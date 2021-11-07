#ifndef STRESSTESTING_H
#define STRESSTESTING_H
#include <stdint.h>


class StressTesting
{
    int stringLengthLimit;
    int maxLimitNum;
    int minlimitNum;
public:
    StressTesting(){
        stringLengthLimit = 20;
        maxLimitNum = 9999;
        minlimitNum = -9999;
    }


    /**
     * @brief testStressTesting_Num
     * @param inputNum
     * @return -1: overMax -2:underMin, otherwise return 1+2+...+(inputNum%100)
     */
    int testStressTesting_Num(int inputNum);

    /**
     * @brief testStressTesting_String
     * @param inputString
     * @return 0: inputStriung is empty -1:inputStriung is nullptr
     *          -2: strlen is large than stringLengthLimit; -3:invaild input
     *          otherwise return strlen;
     */
    int testStressTesting_String(char *inputString);
};

#endif // STRESSTESTING_H
