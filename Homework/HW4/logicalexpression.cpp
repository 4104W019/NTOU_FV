#include "logicalexpression.h"

LogicalExpression::LogicalExpression()
{

}

int LogicalExpression::testLogicalExpression(float inputNumber)
{
    float result = 0;
        if(0 < inputNumber && inputNumber < 10 && inputNumber == (int)inputNumber)
        {
            for(int i=0; i<inputNumber; ++i)
            {
                result += i;
            }
            return result;
        }
        else
            return -1;
}
