#include "mutations.h"

int Mutations::orgProgram(int inputNumber)
{
    int result = 0; //1
    if(1<= inputNumber and inputNumber <= 10){  //2
        for(int i=1; i<=inputNumber; ++i){  //3
            result +=i; //4
        }
        return result;  //5
    }
    return -1;  //6
}

int Mutations::mutProgram_1(int inputNumber)
{
    int result = 10;    //#1    0 -> 10
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<=inputNumber; ++i){
            result +=i;
        }
        return result;
    }
    return -1;
}
int Mutations::mutProgram_2(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber or inputNumber <= 10){   //#2    and -> or
        for(int i=1; i<=inputNumber; ++i){
            result +=i;
        }
        return result;
    }
    return -1;
}
int Mutations::mutProgram_3(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=10; i<=inputNumber; ++i){  //#3    1 -> 10
            result +=i;
        }
        return result;
    }
    return -1;
}
int Mutations::mutProgram_4(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<=inputNumber; ++i){
            result +=inputNumber; //#4    i -> inputNumber
        }
        return result;
    }
    return -1;
}
int Mutations::mutProgram_5(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<=inputNumber; ++i){
            result +=i;
        }
        return inputNumber;  //#5    result -> inputNumber
    }
    return -1;
}
int Mutations::mutProgram_6(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<=inputNumber; ++i){
            result +=i;
        }
        return result;
    }
    return inputNumber;  //#6 -1 -> inputNumber
}
