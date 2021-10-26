#include <QtTest>

// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"

class FormalVerification : public QObject
{
    Q_OBJECT

    void doHW1_data();
    void doHW1();
    void doHW2_data();
    void doHW2();

public:
    FormalVerification();
    ~FormalVerification();

private slots:
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

//    void test_case2_data();
//    void test_case2();
};

void FormalVerification::doHW1_data()
{
    QTest::addColumn<bool>("result");
    QTest::addColumn<bool>("except");

    LineCoverage lineCoverage;
    bool except = true;
    for(int i=-1; i<2; ++i){
        if(i<0)
            except = false;
        else except = true;
        QTest::newRow(QString::number(i).toStdString().c_str()) << lineCoverage.isGreatThanZero(i) << except;
    }
}

void FormalVerification::doHW1()
{
    /**
     * @brief QFETCH
     * This macro can only be used in a test function that is invoked by the test framework.
     * The test function must have a _data function.
     */
    QFETCH(bool, result);
    QFETCH(bool, except);

    QCOMPARE(result, except);
}
void FormalVerification::doHW2_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    EdgeCoverage edgeCoverage;
    int test[4] = {-3,0,5,11};
    int excepts[4] = {-1,0,30,33};  /// sum = 1+2+...+n, if(sum%2) sum /= 2; else sum *= 2

    for(int i=0; i<4; ++i){
        QTest::newRow(QString::number(test[i]).toStdString().c_str()) << edgeCoverage.testLoop(test[i]) << excepts[i];
    }
}

void FormalVerification::doHW2()
{
    /**
     * @brief QFETCH
     * This macro can only be used in a test function that is invoked by the test framework.
     * The test function must have a _data function.
     */
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

FormalVerification::FormalVerification()
{

}

FormalVerification::~FormalVerification()
{

}

void FormalVerification::test_case1_data()
{
    doHW2_data();
}
void FormalVerification::test_case1()
{
    doHW2();
}

QTEST_APPLESS_MAIN(FormalVerification)

#include "tst_formalverification.moc"
