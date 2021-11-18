# LogicalExpression

### Sample Code
```c++
int LogicalExpression::testLogicalExpression(float inputNumber)
{
    float result = 0;   //1
        if(0 < inputNumber && inputNumber < 10 && inputNumber == (int)inputNumber)  //2
        {
            for(int i=0; i<inputNumber; ++i)    //3
            {
                result += i;    //4
            }
            return result;  //5
        }
        else
            return -1;  //6
}

```

### Coverage Report //F
<!-- ![](./pics/CoverageReport.png) -->

### Test-Case
```c++
void Testing::HW4_test_data()
{
    QTest::addColumn<float>("result");
    QTest::addColumn<int>("except");
    LogicalExpression logicalExpression;
    float test[4] = {3,-1,11,1.5};
    int excepts[4] ={6,-1,-1,-1};

    for(int i=0; i<4; ++i){
        QTest::newRow(QString::number(test[i]).toStdString().c_str())
                << logicalExpression.testLogicalExpression(test[i])
                << excepts[i];
    }
}
void Testing::HW4_test()
{
    QFETCH(float, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}
```
### Test Results
>********* Start testing of Testing *********
Config: Using QtTest library 6.2.0, Qt 6.2.0 (arm64-little_endian-lp64 shared (dynamic) release build; by Clang 12.0.5 (clang-1205.0.22.11) (Apple)), macos 11.6
PASS   : Testing::initTestCase()
PASS   : Testing::cleanupTestCase()
Totals: 2 passed, 0 failed, 0 skipped, 0 blacklisted, 1ms
********* Finished testing of Testing *********

### Predicate Coverage  
* test case 1 
    >1. Input values: inputNumber "3" 
    >2. Expected result: "6"
    >3. Test program's result: "6"
    >4. Logical Conditions: `0 < inputNumber && inputNumber < 10 && inputNumber == (int)inputNumber` = "True"
* test case 2
    >1. Input values: inputNumber "-1" 
    >2. EXpected result: "-1"
    >3. Test program's result: "-1"
    >4. Logical Conditions: `0 < inputNumber && inputNumber < 10 && inputNumber == (int)inputNumber` = "False"

### Clause Coverage
* test case 1
    >1. Input values: inputNumber "3" 
    >2. Expected result: "6"
    >3. Test program's result: "6"
    >4. Logical Conditions: `0 < inputNumber` = "True" 
* test case 2
    >1. Input values: inputNumber "-1" 
    >2. Expected result: "-1"
    >3. Test program's result: "-1"
    >4. Logical Conditions: `0 < inputNumber` = "False" 
* test case 3
    >1. Input values: inputNumber "11" 
    >2. Expected result: "-1"
    >3. Test program's result: "-1"
    >4. Logical Conditions: `inputNumber < 10` = "False"
* test case 4
    >1. Input values: inputNumber "1.5" 
    >2. Expected result: "-1"
    >3. Test program's result: "-1"
    >4. Logical Conditions: `inputNumber == (int)inputNumber` = "False"