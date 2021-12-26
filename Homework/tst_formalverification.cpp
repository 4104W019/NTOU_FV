#include <QtTest>

// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"
#include "HW3/stresstesting.h"
#include "HW7/inputbox_phone_number.h"
#include<QDebug>
class FormalVerification : public QObject
{
    Q_OBJECT

public:
    FormalVerification();
    ~FormalVerification();
private slots:
    void HW3_stress_test_data();
    void HW3_stress_test();
private:
    /**
     * @brief test_case1_data
     * fill the test pattern for test_case1.
     */
    void test_case1_data();

    /**
     * @brief test_case1
     * The test data has two elements, bool except and result
     * To fetch these values in the actual test
     */
    void test_case1();
//private:
    void test_case2_data();
    void test_case2();
    void test_case22_data();
    void test_case22();

};

FormalVerification::FormalVerification()
{

}

FormalVerification::~FormalVerification()
{

}

void FormalVerification::test_case1_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    LineCoverage lineCoverage;
    uint32_t test[2] = {17,9};
    int excepts[2] = {-1,45};

    for(int i=0; i<2; ++i){
        QTest::newRow(QString::number(test[i]).toStdString().c_str())
                << lineCoverage.thePartialSums(test[i]) ///< here
                << excepts[i];
    }
}

void FormalVerification::test_case1()
{
    QFETCH(int, result);
    QFETCH(int, except);

    QCOMPARE(result, except);
}

void FormalVerification::test_case2_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    EdgeCoverage edgeCoverage;
    int test[3] = {-3,0,5};
    int excepts[3] = {-1,0,30};  /// sum = 1+2+...+n, if(sum%2) sum /= 2; else sum *= 2

    for(int i=0; i<3; ++i){
        QTest::newRow(QString::number(test[i]).toStdString().c_str())
                << edgeCoverage.testLoop(test[i])
                << excepts[i];
    }
}

void FormalVerification::test_case2()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

void FormalVerification::test_case22_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    EdgeCoverage edgeCoverage;
    uint32_t test[3] = {11,5,0};
    int excepts[3] = {-1,15,0};

    for(int i=0; i<3; ++i){
        QTest::newRow(QString::number(test[i]).toStdString().c_str())
                << edgeCoverage.testEdgePairCoverage(test[i])
                << excepts[i];
    }
}

void FormalVerification::test_case22()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

void FormalVerification::HW3_stress_test_data()
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

#include "tst_formalverification.moc"
