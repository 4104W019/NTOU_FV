#include <QtTest>

// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"

class FormalVerification : public QObject
{
    Q_OBJECT

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

    void test_case2_data();
    void test_case2();
};

FormalVerification::FormalVerification()
{

}

FormalVerification::~FormalVerification()
{

}

void FormalVerification::test_case1_data()
{
    QTest::addColumn<char>("result");
    QTest::addColumn<char>("except");

    LineCoverage lineCoverage;
    int test[7] = {-3,0,30,82,93,100,101};
    char excepts[7] = {'X','C','C','B','A','A','X'};

    for(int i=0; i<7; ++i){
        QTest::newRow(QString::number(test[i]).toStdString().c_str()) << lineCoverage.theScoreGrade(test[i]) << excepts[i];
    }
}
void FormalVerification::test_case1()
{
    /**
     * @brief QFETCH
     * This macro can only be used in a test function that is invoked by the test framework.
     * The test function must have a _data function.
     */
    QFETCH(char, result);
    QFETCH(char, except);

    QCOMPARE(result, except);
}

void FormalVerification::test_case2_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    EdgeCoverage edgeCoverage;
    int test[4] = {-3,0,5,11};
    int excepts[4] = {-1,0,30,33};  /// sum = 1+2+...+n, if(sum%2) sum /= 2; else sum *= 2

    for(int i=0; i<4; ++i){
        QTest::newRow(QString::number(i).toStdString().c_str()) << edgeCoverage.testLoop(test[i]) << excepts[i];
    }
}
void FormalVerification::test_case2()
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


QTEST_APPLESS_MAIN(FormalVerification)

#include "tst_formalverification.moc"
