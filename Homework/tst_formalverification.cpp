#include <QtTest>
#include <QStringList>
// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"
#include "HW3/stresstesting.h"
class FormalVerification : public QObject
{
    Q_OBJECT

public:
    FormalVerification();
    ~FormalVerification();


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
    private slots:
    void testHW3Num_data();
    void testHW3Num();
    void testHW3Str_data();
    void testHW3Str();
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
void FormalVerification::testHW3Num_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    StressTesting st;
    int32_t test[3] = {88888888,-7777777,567};
    int excepts[4] = {-1,-2,15};

    for(int i=0; i<3; ++i){
        QTest::newRow(QString("case-%1: input:%2 except:%3").arg(i+1).arg(test[i]).arg(excepts[i]).toStdString().c_str())
                << st.testStressTesting_Num(test[i])
                << excepts[i];
    }
}
void FormalVerification::testHW3Num()
{
    QFETCH(int, except);
    QFETCH(int, result);
    QCOMPARE(except, result);
}


void FormalVerification::testHW3Str_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");



    char *inputStr[5] = {nullptr};
    int excepts[5] = {0,-1,-2,-3,55};

    char empty ='\0';
    char invaild = 1;
    char *largeNumStr = new char[2*1024*1024];
    memset(largeNumStr,'A',2*1024*1024);
    char hello_NTOU[] = "Hello NTOU";

    inputStr[0] = &empty;
    inputStr[2] = largeNumStr;
    inputStr[3] = &invaild;
    inputStr[4] = hello_NTOU;

    QStringList testCase;
    testCase<<"empty"<<"nullptr"<<"longString"<<"invalid"<<"normalString";

    StressTesting st;
    for(int i=0; i<5; ++i){
        QTest::newRow(QString("case-%1: input:%2 except:%3").arg(i+1).arg(testCase.at(i)).arg(excepts[i]).toStdString().c_str())
                << st.testStressTesting_String(inputStr[i])
                << excepts[i];
    }
    if(largeNumStr){
        delete []largeNumStr;
        largeNumStr = nullptr;
    }
}
void FormalVerification::testHW3Str()
{
    QFETCH(int, except);
    QFETCH(int, result);
    QCOMPARE(except, result);
}

QTEST_APPLESS_MAIN(FormalVerification)

#include "tst_formalverification.moc"
