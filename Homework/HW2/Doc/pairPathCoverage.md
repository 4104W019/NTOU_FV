<H1>HW2: Pair/Path Coverage </H1>
[TOC]
---
## 1. Sample Code
```c++  {.line-numbers}
int EdgeCoverage::testEdgePairCoverage(uint32_t inputNumber)//1
{
    int result = 0;		//2
    if(inputNumber < 10)	//3
    {
        for(uint32_t i = 1; i <= inputNumber; ++i)
        {		//4		//5		//6
           result += i;		//7
        }
        return result;		//8
    }
    else
        return -1;		//9
}
```
--- 
## 2. Flow Chart
![](./pics/GraphCoverage.png)

--- 

## 3. Result of the testing.
#### 3-1. Test Cases
```c {.line-numbers}
void Testing::HW22_test_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    EdgeCoverage edgeCoverage;
    uint32_t test[3] = {11,5,0};
    int excepts[3] = {-1,15,0};

    for(int i=0; i<3; ++i){
        QString description = QString("HW22(testEdgePairCoverage) Input = %1, Excepted = %2").arg(test[i]).arg(excepts[i]);

        QTest::newRow(description.toStdString().c_str())
                << edgeCoverage.testEdgePairCoverage(test[i])
                << excepts[i];
    }
}
void Testing::HW22_test()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}
```

#### 3-2. Result of the test cases.
```sh
PASS   : HW22(testEdgePairCoverage) Input = 11, Excepted = -1
PASS   : HW22(testEdgePairCoverage) Input = 5, Excepted = 15
PASS   : HW22(testEdgePairCoverage) Input = 0, Excepted = 0
```
--- 
## 4. Report of Test cases.
### 4-1. Edge-Pair Coverage
   
#### **PairCoverage Test-case 1:**
    >1. Input values: inputNumber "11" 
    >2. Expected result: "-1"
    >3. Test program's result: "-1"
    >4. Edge-Pair Coverage: (1,2,3),(2,3,9)
    >5. Path Coverage: {1,2,3,9}
#### **PairCoverage Test-case 2:**
    >1. Input values: inputNumber "5" 
    >2. EXpected result: "15"
    >3. Test program's result: "15"
    >4. Edge-Pair Coverage:  (1,2,3)(2,3,4),
              (3,4,5),(4,5,6),(5,6,7)(7,5,8)
    >5. Path Coverage: {1,2,3,4,5,6,7,8} //loop
#### **PairCoverage Test-case 3:**
    >1. Input values: inputNumber "0" 
    >2. EXpected result: "0"
    >3. Test program's result: "0"
    >4. Edge-Pair Coverage: (1,2,3)(2,3,4),
                            (3,4,5)(4,5,8)
    >5. Path Coverage: {1,2,3,4,5,8} //no loop

### 4-2. Test Path Coverage
#### **PathCoverage Test-case 1:**
    >1. Input values: inputNumber "17"
    >2. Expecteㄒd result: "-1"
    >3. Test program's result: "-1"
    >4. Test Path Coverage: 1->9(1,2,3,9)
#### **PathCoverage Test-case 2:**
    >1. Input values: inputNumber "0"
    >2. Expected result: "0"
    >3. Test program's result: "0"
    >4. Test Path Coverage: 1->8(1,2,3,4,5,8)	//no loop
#### **PathCoverage Test-case 3:**
    >1. Input values: inputNumber "2"
    >2. Expected result: "3"
    >3. Test program's result: "3"
    >4. Test Path Coverage: 1->8(1,2,3,4,5,7,6,5,7,6,5,8)	//loop

---

## 5. Coverage Report
![](./pics/CoverageReport.png)


