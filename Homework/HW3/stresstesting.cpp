#include "stresstesting.h"
#include <string.h>
#include <stdio.h>



int StressTesting::testStressTesting_Num(int inputNum)
{
    int ret=0;
    if(inputNum > maxLimitNum)
        return -1;
    else if(inputNum < minlimitNum)
        return -2;

    else
    {
        int loop = inputNum/100;
        for(int i=0; i<=loop; ++i)
        {
            ret += i;
        }
    }

    return ret;
}

int StressTesting::testStressTesting_String(char *inputString)
{
    if(inputString != nullptr)
    {
        int inputStringLength = strlen(inputString);

        if(inputString[0] == '\0')
            return 0; // zero
        else
        {
            if(inputStringLength > stringLengthLimit)
                return -2;
            else{
                int ret=0;
                for(int i = 0 ; i < inputStringLength; ++i)
                {
                    if(inputString[i]<0x20)// || inputString[i]==0x7f)
                        return -3;
                    else
                        ret+=(i+1);
                }
                return ret;
            }
        }
    }
    return -1; // nullptr
}
