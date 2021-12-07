#include "mutations.h"

int Mutations::orgProgram(int inputNumber)
{
    int result = 0; //1
    if(1<= inputNumber and inputNumber <= 10){  //2
        for(int i=1; i<=inputNumber; ++i){  //3,4,5
            result +=i; //6
        }
        return result;  //7
    }
    return -1;  //8
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
int Mutations::mutProgram_4(int inputNumber)    //inputNumber = 4
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<inputNumber; ++i){  //#4   <= -> <
            result +=i;
        }
        return result;  //1+2+3
    }
    return -1;
}
int Mutations::mutProgram_5(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){  //inputNumber = 4
        for(int i=1; i<=inputNumber; i=i+2){  //#5    ++i -> i=i+2
            result +=i;
        }
        return result;  //
    }
    return -1;
}
int Mutations::mutProgram_6(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<=inputNumber; ++i){
            result +=inputNumber; //#6    i -> inputNumber
        }
        return result;
    }
    return -1;
}
int Mutations::mutProgram_7(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<=inputNumber; ++i){
            result +=i;
        }
        return inputNumber;  //#7    result -> inputNumber
    }
    return -1;
}
int Mutations::mutProgram_8(int inputNumber)
{
    int result = 0;
    if(1<= inputNumber and inputNumber <= 10){
        for(int i=1; i<=inputNumber; ++i){
            result +=i;
        }
        return result;
    }
    return inputNumber;  //#8 -1 -> inputNumber
}
