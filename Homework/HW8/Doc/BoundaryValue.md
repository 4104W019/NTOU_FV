# BoundaryValue

### Sample Code
```c++  {.line-numbers}
using namespace std;

int BoundaryValue::testBoundaryValue(int current_temperature)
{
        // config
        int temperature_thresh_cold = 16;
        int temperature_thresh_hot = 28;
        int status = -1;
        
        if(current_temperature <= temperature_thresh_cold){
                cout << '溫度過冷, 啟動暖氣' << endl;
                status = 1;
        }else if(current_temperature >= temperature_thresh_hot){
                cout << '溫度過熱, 啟動冷氣' << endl;
                status = 2;
        }else{
                cout << '溫度正常...' << endl;
                status = 0;
        }

        return status;
}

```


### Test-Case HW 8

### BoundaryValue Converage
* test case 1 
    >1. Input values: current_temperature: 15 
    >2. Expected result: "1"
    >3. Test program's result: "1"
* test case 2
    >1. Input values: current_temperature: 16
    >2. Expected result: "1"
    >3. Test program's result: "1"
* test case 3 
    >1. Input values: current_temperature: 17
    >2. Expected result: "0"
    >3. Test program's result: "0"
* test case 4
    >1. Input values: current_temperature: 27
    >2. Expected result: "0"
    >3. Test program's result: "0"
* test case 5
    >1. Input values: current_temperature: 28
    >2. Expected result: "2"
    >3. Test program's result: "2"
* test case 6
    >1. Input values: current_temperature: 29
    >2. Expected result: "2"
    >3. Test program's result: "2"


### Test Results
```
PASS   : Testing::HW8_test(HW 8 test_case_01 -> current_temperature: 15)
PASS   : Testing::HW8_test(HW 8 test_case_02 -> current_temperature: 16)
PASS   : Testing::HW8_test(HW 8 test_case_03 -> current_temperature: 17)
PASS   : Testing::HW8_test(HW 8 test_case_04 -> current_temperature: 27)
PASS   : Testing::HW8_test(HW 8 test_case_05 -> current_temperature: 28)
PASS   : Testing::HW8_test(HW 8 test_case_06 -> current_temperature: 29)
```


### HW 8 Test Code
```c++
    // HW 8 test_case_01
    QString descriptions_test_case_01 = QString("HW 8 test_case_01 -> current_temperature: 15");
    int current_temperature = 15;
    int excepted_status = 1;

    QTest::newRow(descriptions_test_case_01.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_02
    QString descriptions_test_case_02 = QString("HW 8 test_case_02 -> current_temperature: 16");
    current_temperature = 16;
    excepted_status = 1;

    QTest::newRow(descriptions_test_case_02.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_03
    QString descriptions_test_case_03 = QString("HW 8 test_case_03 -> current_temperature: 17");
    current_temperature = 17;
    excepted_status = 0;

    QTest::newRow(descriptions_test_case_03.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_04
    QString descriptions_test_case_04 = QString("HW 8 test_case_04 -> current_temperature: 27");
    current_temperature = 27;
    excepted_status = 0;

    QTest::newRow(descriptions_test_case_04.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_05
    QString descriptions_test_case_05 = QString("HW 8 test_case_05 -> current_temperature: 28");
    current_temperature = 28;
    excepted_status = 2;

    QTest::newRow(descriptions_test_case_05.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_06
    QString descriptions_test_case_06 = QString("HW 8 test_case_06 -> current_temperature: 29");
    current_temperature = 29;
    excepted_status = 2;

    QTest::newRow(descriptions_test_case_06.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;
```
