# LogicalExpression

### Sample Code
```c++
int LogicalExpression::testLogicalExpression(int* Amounts, int amountSize, bool isBlackFriday,
                                             bool isChristmas)
{
        // config
        int amount_to_get_discount = 1000;
        float special_discount = 1.0;
        
        // calculate total_amount
        int total_amount = 0;
        for(int i=0; i < amountSize; ++i)
        {
                total_amount += Amounts[i];
        }

        // calculate discount
        if ( total_amount >= amount_to_get_discount && ( isBlackFriday || isChristmas ) )
        {
                special_discount = 0.65;
        }else{
                special_discount = 0.9;
        }

        total_amount = (int)(total_amount * special_discount);
        
        return total_amount;
}


```


### Test-Case HW 4-1

### Predicate Coverage  
* test case 1 
    >1. Input values: amounts: [100, 500, 600], is_black_friday: true, is_cristmas: false
    >2. Expected result: "780"
    >3. Test program's result: "780"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount && ( isBlackFriday || isChristmas ) ` = "True"
* test case 2
    >1. Input values: amounts: [100, 500, 600], is_black_friday: false, is_cristmas: false 
    >2. EXpected result: "1080"
    >3. Test program's result: "1080"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount && ( isBlackFriday || isChristmas ) ` = "False"


### Test Results
```
PASS   : Testing::HW4_test(HW 4-1 test_case_01 -> total condition: true)
PASS   : Testing::HW4_test(HW 4-1 test_case_02 -> total condition: false)
```


### HW 4-1 Test Code
```c++

// HW 4-1 test_case_01
QString descriptions_test_case_01 = QString("HW 4-1 test_case_01 -> total condition: true");
int data_test_case_01[3] = { 100, 500, 600 };
int *amounts = data_test_case_01;
int amount_size = 3;
bool is_black_friday = true;
bool is_christmas = false;
int discounted_amount = 780;

QTest::newRow(descriptions_test_case_01.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;


// HW 4-1 test_case_02
QString descriptions_test_case_02 = QString("HW 4-1 test_case_02 -> total condition: false");
int data_test_case_02[3] = { 100, 500, 600 };
amounts = data_test_case_02;
is_black_friday = false;
is_christmas = false;
discounted_amount = 1080;

QTest::newRow(descriptions_test_case_02.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;
```
    
    
### Test-Case HW 4-2

### Clause Coverage
* test case 1
    >1. Input values: amounts: [100, 500, 600], is_black_friday: false, is_cristmas: true
    >2. Expected result: "780"
    >3. Test program's result: "780"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: false, isBlackFriday: false, isChristmas: false`
* test case 2
    >1. Input values: amounts: [100, 500, 600], is_black_friday: false, is_cristmas: false
    >2. Expected result: "540"
    >3. Test program's result: "540"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: false, isBlackFriday: false, isChristmas: false`


### Test Results
```
PASS   : Testing::HW4_test(HW 4-2 test_case_01 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true)
PASS   : Testing::HW4_test(HW 4-2 test_case_02 -> >= amount_to_get_discount: false, isBlackFriday: false, isChristmas: false)
```


### HW 4-2 Test Code
```c++

// HW 4-2 test_case_01
QString descriptions_hw42_test_case_01 = QString("HW 4-2 test_case_01 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true");
int data_hw42_test_case_01[3] = { 100, 500, 600 };
amounts = data_hw42_test_case_01;
is_black_friday = true;
is_christmas = true;
discounted_amount = 780;

QTest::newRow(descriptions_hw42_test_case_01.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;

// HW 4-2 test_case_02
QString descriptions_hw42_test_case_02 = QString("HW 4-2 test_case_02 -> >= amount_to_get_discount: false, isBlackFriday: false, isChristmas: false");
int data_hw42_test_case_02[3] = { 100, 200, 300 };
amounts = data_hw42_test_case_02;
is_black_friday = false;
is_christmas = false;
discounted_amount = 540;

QTest::newRow(descriptions_hw42_test_case_02.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;

```
    
    
### Test-Case HW 4-3


### Combinatorial Coverage
* test case 1 ( T T T )
    >1. Input values: amounts: [100, 500, 600], is_black_friday: true, is_cristmas: true
    >2. Expected result: "780"
    >3. Test program's result: "780"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true`
    
* test case 2 ( F T T )
    >1. Input values: amounts: [100, 200, 300], is_black_friday: true, is_cristmas: true
    >2. Expected result: "540"
    >3. Test program's result: "540"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: false, isBlackFriday: true, isChristmas: true`
    
* test case 3 ( T T F )
    >1. Input values: amounts: [100, 500, 600], is_black_friday: true, is_cristmas: false
    >2. Expected result: "780"
    >3. Test program's result: "780"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: false`
    
* test case 4 ( F T F )
    >1. Input values: amounts: [100, 200, 300], is_black_friday: true, is_cristmas: false
    >2. Expected result: "540"
    >3. Test program's result: "540"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: false, isBlackFriday: true, isChristmas: false`
    
* test case 5 ( T F T )
    >1. Input values: amounts: [100, 500, 600], is_black_friday: false, is_cristmas: true
    >2. Expected result: "780"
    >3. Test program's result: "780"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: true`
    
* test case 6 ( F F T )
    >1. Input values: amounts: [100, 200, 300], is_black_friday: false, is_cristmas: true
    >2. Expected result: "540"
    >3. Test program's result: "540"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: false, isBlackFriday: false, isChristmas: true`
    
* test case 7 ( T F F )
    >1. Input values: amounts: [100, 500, 600], is_black_friday: false, is_cristmas: false
    >2. Expected result: "1080"
    >3. Test program's result: "1080"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: false`

* test case 8 ( F F F )
    >1. Input values: amounts: [100, 200, 300], is_black_friday: false, is_cristmas: false
    >2. Expected result: "540"
    >3. Test program's result: "540"
    >4. Logical Conditions: `total_amount >= amount_to_get_discount: false, isBlackFriday: false, isChristmas: false`


### Test Results
```
PASS   : Testing::HW4_test(HW 4-3 test_case_01 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true)
PASS   : Testing::HW4_test(HW 4-3 test_case_02 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true)
PASS   : Testing::HW4_test(HW 4-3 test_case_03 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: false)
PASS   : Testing::HW4_test(HW 4-3 test_case_04 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: false)
PASS   : Testing::HW4_test(HW 4-3 test_case_05 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: true)
PASS   : Testing::HW4_test(HW 4-3 test_case_06 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: true)
PASS   : Testing::HW4_test(HW 4-3 test_case_07 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: false)
PASS   : Testing::HW4_test(HW 4-3 test_case_08 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: false)
```


### HW 4-3 Test Code
```c++
// HW 4-3 test_case
int data_hw43_true[3] = { 100, 500, 600 };
int *amounts_true = data_hw43_true;
int data_hw43_false[3] = { 100, 200, 300 };
int *amounts_false = data_hw43_false;

QString descriptions_hw43_test_case_01 = QString("HW 4-3 test_case_01 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true");
is_black_friday = true;
is_christmas = true;
discounted_amount = 780;
QTest::newRow(descriptions_hw43_test_case_01.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;
QString descriptions_hw43_test_case_02 = QString("HW 4-3 test_case_02 -> >= amount_to_get_discount: false, isBlackFriday: true, isChristmas: true");
discounted_amount = 540;
QTest::newRow(descriptions_hw43_test_case_02.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;

QString descriptions_hw43_test_case_03 = QString("HW 4-3 test_case_03 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: false");
is_black_friday = true;
is_christmas = false;
discounted_amount = 780;
QTest::newRow(descriptions_hw43_test_case_03.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;
QString descriptions_hw43_test_case_04 = QString("HW 4-3 test_case_04 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: false");
discounted_amount = 540;
QTest::newRow(descriptions_hw43_test_case_04.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;

QString descriptions_hw43_test_case_05 = QString("HW 4-3 test_case_05 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: true");
is_black_friday = false;
is_christmas = true;
discounted_amount = 780;
QTest::newRow(descriptions_hw43_test_case_05.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;
QString descriptions_hw43_test_case_06 = QString("HW 4-3 test_case_06 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: true");
discounted_amount = 540;
QTest::newRow(descriptions_hw43_test_case_06.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;

QString descriptions_hw43_test_case_07 = QString("HW 4-3 test_case_07 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: false");
is_black_friday = false;
is_christmas = false;
discounted_amount = 1080;
QTest::newRow(descriptions_hw43_test_case_07.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;
QString descriptions_hw43_test_case_08 = QString("HW 4-3 test_case_08 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: false");
discounted_amount = 540;
QTest::newRow(descriptions_hw43_test_case_08.toStdString().c_str())
              << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                         is_black_friday, is_christmas)
              << discounted_amount;

```


