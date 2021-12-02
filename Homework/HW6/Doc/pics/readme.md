<h1>HW6: Mutation test </h1> 	

[TOC]

---
## 1. Sample Code
```c++
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
```

---

## 2. Result of the testing.
> ********* Start testing of Testing *********
Config: Using QtTest library 6.2.0, Qt 6.2.0 (arm64-little_endian-lp64 shared (dynamic) release build; by Clang 12.0.5 (clang-1205.0.22.11) (Apple)), macos 11.6
PASS   : Testing::initTestCase()
PASS   : Testing::HW6_test(-1)
PASS   : Testing::HW6_test(0)
PASS   : Testing::HW6_test(1)
PASS   : Testing::HW6_test(4)
PASS   : Testing::HW6_test(11)
FAIL!  : Testing::HW6_test(1) Compared values are not the same
   Actual   (except): 1
   Expected (result): 11
   Loc: [../Homework/tst_formalverification.cpp(217)]
FAIL!  : Testing::HW6_test(0) Compared values are not the same
   Actual   (except): -1
   Expected (result): 0
   Loc: [../Homework/tst_formalverification.cpp(217)]
FAIL!  : Testing::HW6_test(4) Compared values are not the same
   Actual   (except): 10
   Expected (result): 0
   Loc: [../Homework/tst_formalverification.cpp(217)]
FAIL!  : Testing::HW6_test(4) Compared values are not the same
   Actual   (except): 10
   Expected (result): 16
   Loc: [../Homework/tst_formalverification.cpp(217)]
FAIL!  : Testing::HW6_test(4) Compared values are not the same
   Actual   (except): 10
   Expected (result): 4
   Loc: [../Homework/tst_formalverification.cpp(217)]
FAIL!  : Testing::HW6_test(0) Compared values are not the same
   Actual   (except): -1
   Expected (result): 0
   Loc: [../Homework/tst_formalverification.cpp(217)]
PASS   : Testing::cleanupTestCase()
Totals: 7 passed, 6 failed, 0 skipped, 0 blacklisted, 1ms
********* Finished testing of Testing *********

---

## 3. Report of Test cases.
#### **Ｍutation Test-case 1:**
1. Input values: inputNumber 1
2. expected result: 1
3. test origiol program-s result: 1
4. test mutant program's result: 11
#### **Ｍutation Test-case 2:**
1. Input values: inputNumber 0
2. expected result: -1
33. test origiol program-s result: -1
4. test mutant program's result: 0
#### **Ｍutation Test-case 3:**
1. Input values: inputNumber 4
2. expected result: 10
3. test origiol program-s result: 10
4. test mutant program's result: 0
#### **Ｍutation Test-case 4:**
1. Input values: inputNumber 4
2. expected result: 10
3. test origiol program-s result: 10
4. test mutant program's result: 16
#### **Ｍutation Test-case 5:**
1. Input values: inputNumber 4
2. expected result: 10
3. test origiol program-s result: 10
4. test mutant program's result: 4
#### **Ｍutation Test-case 6:**
1. Input values: inputNumber 0
2. expected result: -1
3. test origiol program-s result: -1
4. test mutant program's result: 0

---

## 4. Coverage Report

