# HW7 - 有效值測試 (2021-12-10)-(2021-12-26)

## 待測程式

```c++ {.line-numbers}

static int __validate_length(QString n)
{
    return (8 <= n.length() && n.length() <= 13) ? 0:-1;
}

static int __validate_beging_char(QString n)
{
    if (n.at(0) == QString("+") || n[0].isDigit())
        return 0;
    return -1;
}

static int __validate_char(QString n)
{
    for(int i = 1; i< n.length(); i++)
    {
        if (!n[i].isDigit())
            return -1;
    }
    return 0;
}

int InputBox_phone_number::__validate_phone_number(QString n)
{
    int rev;

    if ((rev = __validate_length(n)) == -1) return rev;
    if ((rev = __validate_beging_char(n)) == -1) return rev;
    if ((rev = __validate_char(n)) == -1) return rev;
    return rev;
}

```

## 測式程式

```C++
void FormalVerification::HW7_validate_test_data()
{

    struct patten{
        const char *desc;
        QString phone_no;
        int except;
    } ps [] = {
        {"1 3 5 7", "021234567", 0},
        {"2 3 5 7", "1234567", -1},
        {"1 4 5 7", "12345678901234", -1},
        {"1 3 6 7", "-886918123456", -1},
        {"1 3 5 8", "+88692812345a", -1},
        {NULL, NULL, 0}
    }, *p = ps;


    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    int ret;
    InputBox_phone_number phone_number;
    for (; p->desc != nullptr; p++) {

        ret = phone_number.__validate_phone_number(p->phone_no);

        QString descriptions = QString("現在測式:(%1), 輸入電話:(%2), 輸入長度(%3), 期望輸出(%4) 實際輸出(%5)")
            .arg(QString(p->desc), +5, QLatin1Char(' '))
            .arg(p->phone_no)
            .arg(p->phone_no.length())
            .arg(p->except)
            .arg(ret);

        QTest::newRow(descriptions.toStdString().c_str()) << ret << p->except;
    }


}

void FormalVerification::HW3_stress_test()
{
    QFETCH(int, result);
    QFETCH(int, except);

    QCOMPARE(except,result);
}

QTEST_APPLESS_MAIN(FormalVerification)
void FormalVerification::HW7_validate_test()
{
    QFETCH(int, result);
    QFETCH(int, except);

    QCOMPARE(except,result);
}


```

程式測式項目
* 符合長度 >= 8
* 符合長度 <= 13
* 第一個字元可以是"+"號或數字0-9
* 第二個字完後必須是數字0-9


| 程式測式項目 | True | False |
| - | - | - |
| 符合長度 >= 8 | 1 | 2 |
| 符合長度 <= 13 | 3 | 4 |
| 第一個字元可以是"+"號或數字0-9 | 5 | 6 |
| 第二個字完後必須是數字0-9 | 7 | 8 |

| 測式案例 | 測式項目 |
| - | - |
| 1 | 1, 3, 5, 7 |
| 2 | 2, 3, 5, 7 |
| 3 | 1, 4, 4, 7 |
| 4 | 1, 3, 6, 7 |
| 5 | 1, 3, 5, 8 |

## 執行輸出


>Homework $ ./Homework
```
Homework $ ./Homework
Config: Using QtTest library 5.12.8, Qt 5.12.8 (x86_64-little_endian-lp64 shared (dynamic) release build; by GCC 9.3.0)
PASS   : FormalVerification::initTestCase()
PASS   : FormalVerification::HW3_stress_test(現在測式:(1 3 5 7), 輸入電話:(021234567), 輸入長度(9), 期望輸出(0) 實際輸出(0))
PASS   : FormalVerification::HW3_stress_test(現在測式:(2 3 5 7), 輸入電話:(1234567), 輸入長度(7), 期望輸出(-1) 實際輸出(-1))
PASS   : FormalVerification::HW3_stress_test(現在測式:(1 4 5 7), 輸入電話:(12345678901234), 輸入長度(14), 期望輸出(-1) 實際輸出(-1))
PASS   : FormalVerification::HW3_stress_test(現在測式:(1 3 6 7), 輸入電話:(-886918123456), 輸入長度(13), 期望輸出(-1) 實際輸出(-1))
PASS   : FormalVerification::HW3_stress_test(現在測式:(1 3 5 8), 輸入電話:(+88692812345a), 輸入長度(13), 期望輸出(-1) 實際輸出(-1))
PASS   : FormalVerification::cleanupTestCase()
Totals: 7 passed, 0 failed, 0 skipped, 0 blacklisted, 14ms
********* Finished testing of FormalVerification *********



```
#### **Test-case 1:**
> 1) Input values: 輸入電話:(021234567), 輸入長度(9)
> 2) expected result(正確的結果): 0
> 3) test program's result: 0
> 4) criteria analysis: **(1), (3), (5), 7)**: 
符合長度 >= 8，符合長度 <= 13，
第一個字元可以是 **+** 號
或數字 **0-9** ，第二個字完後必須是數字0-9

#### **Test-case 2:**
> 1) Input values:  輸入電話:(1234567), 輸入長度(7)
> 2) expected result(正確的結果): -1
> 3) test program's result: -1
> 4) criteria analysis: **(2), (3), **: **不符合** 長度 >= 8
#### **Test-case 3:**
> 1) Input values: 輸入電話:(12345678901234), 輸入長度(14)
> 2) expected result(正確的結果): -1
> 3) test program's result: -1
> 4) criteria analysis: **(4)** 符合長度 >= 8, **不符合** 長度 <= 13
#### **Test-case 4:**
> 1) Input values: 輸入電話:(-886918123456), 輸入長度(13)
> 2) expected result(正確的結果): -1
> 3) test program's result: -1
> 4) criteria analysis: **(6)** : **不符合** 第一個字元可以是"+"號或數字0-9

#### **Test-case 5:**
> 1) Input values: 輸入電話:(+88692812345a), 輸入長度(13)
> 2) expected result(正確的結果): -1
> 3) test program's result: -1
> 4) criteria analysis: **(8)**: **不符合** 第二個字完後必須是數字0-9

