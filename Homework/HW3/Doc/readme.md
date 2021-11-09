<h1>HW3: Stress Testing</h1>
[TOC]
---

## 1. Sample Code
examples...
```c
int HW3::test1(){
    return 1;
}

int HW3::test2(){
    return 1;
}
```

---
## 2. Flow Chart
example...

>ditaa {cmd=true args=["-E"] hide=true }
```puml
start
:test1;
 note right
 (1)
 end note
:inputnum = 1;
 note right
 (2)
 end note
if(aaa) then(yes)
 :doAAA;
 note right
 (4)
 end note
else (no)
 :doBBB;
  note right
 (5)
 end note
endif

:int i=0;
 note right
 (6)
 end note
repeat :i<10;
:doSomething;
repeat while(i = i+1)

end
```

---

## 3. test result
```sh
********* Start testing of FormalVerification *********
Config: Using QtTest library 6.2.0, Qt 6.2.0 (x86_64-little_endian-llp64 shared (dynamic) release build; by GCC 8.1.0), windows 10PASS   : FormalVerification::initTestCase()
PASS   : FormalVerification::testHW3Num(case-1: input:88888888 except:-1)
PASS   : FormalVerification::testHW3Num(case-2: input:-7777777 except:-2)
PASS   : FormalVerification::testHW3Num(case-3: input:567 except:15)
PASS   : FormalVerification::testHW3Str(case-1: input:empty except:0)
PASS   : FormalVerification::testHW3Str(case-2: input:nullptr except:-1)
PASS   : FormalVerification::testHW3Str(case-3: input:longString except:-2)
PASS   : FormalVerification::testHW3Str(case-4: input:invalid except:-3)
PASS   : FormalVerification::testHW3Str(case-5: input:normalString except:55)
PASS   : FormalVerification::cleanupTestCase()
Totals: 10 passed, 0 failed, 0 skipped, 0 blacklisted, 2ms
********* Finished testing of FormalVerification *********
```

---

## 4. Homework 1 Report
**Test-case 1:**
|Items|Description|
|----|----|
|Input values|88888888|
|Expected result|-1|
|Test program's result|-1|
|Criteria report|...|


**Test-case 2:**
|Items|Description|
|----|----|
|Input values|-7777777|
|Expected result|-2|
|Test program's result|-2|
|Criteria report|...|

**Test-case 3:**
|Items|Description|
|----|----|
|Input values|567|
|Expected result|15|
|Test program's result|15|
|Criteria report|...|
---

## 5. Coverage Report
![](./pics/2021-11-09-12-02-20.png)
![](./pics/2021-11-09-12-02-50.png)
---