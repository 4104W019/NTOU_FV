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

    void test_case1_1_data();
    void test_case1_1();
    void test_EdgePair_data();
    void test_EdgePair();
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
void FormalVerification::test_case1_1_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<int>("expect");

    QTest::newRow("<Null>")     << ""           << 0;
    QTest::newRow("Monday")     << "Monday"     << 1;
    QTest::newRow("Tuesday")    << "Tuesday"    << 2;
    QTest::newRow("Wednesday")  << "Wednesday"  << 3;
    QTest::newRow("Thursday")   << "Thursday"   << 4;
    QTest::newRow("Friday")     << "Friday"     << 5;
    QTest::newRow("Saturday")   << "Saturday"   << 6;
    QTest::newRow("Sunday")     << "Sunday"     << 7; /* 找到程式上的錯誤!  (lineCoverage::WeekName2Numbe) */
    QTest::newRow("Out of")     << "ABCDEFB"    << 0;
}
void FormalVerification::test_EdgePair_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<int>("expect");

    //QTest::newRow("Edge 1 - 2")     << "None"       << 0; // 不測
    //QTest::newRow("Edge 2 - 3")     << "Monday"     << 1; // 不測
    QTest::newRow("Edge 3 - 4")    << "None"    << 0;
    QTest::newRow("Edge 4 - 5")    << "None"    << 0;
    QTest::newRow("Edge 4 - 8")    << "OutOfRange" << 0;
    QTest::newRow("Edge 5 - 6")   << "Monday"   << 1;
    QTest::newRow("Edge 5 - 7")     << "Monday"     << 1;
    QTest::newRow("Edge 6 - 4")     << "Monday"     << 1;

}
void FormalVerification::test_EdgePair()
{
    LineCoverage lineCoverage;

    QFETCH(QString, input);
    QFETCH(int, expect);

    QCOMPARE(lineCoverage.WeekName2Number(input), expect);
}
void FormalVerification::test_case1_1()
{
    LineCoverage lineCoverage;

    QFETCH(QString, input);
    QFETCH(int, expect);
    QCOMPARE(lineCoverage.WeekName2Number(input), expect);

}
QTEST_APPLESS_MAIN(FormalVerification)

#include "tst_formalverification.moc"
