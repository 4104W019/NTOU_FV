#include <QtTest>

// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"
#include "HW3/stresstesting.h"

class FormalVerification : public QObject
{
    Q_OBJECT

public:
    FormalVerification();
    //~FormalVerification();
private slots:
//    void HW3_stress_test_data();
//    void HW3_stress_test();
    void HW3_test();
    void HW3_test_data();
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

//FormalVerification::~FormalVerification()
//{
//}

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

#if 0
void FormalVerification::HW3_stress_test_data()
{
    struct patten{
        const char *desc;
        const char *path;
        int except;
    } ps [] = {
        {"空指標", NULL, -2},
        {"長度為0", "", -1},
        {"最小輸入", "/", 0},
        {"一般","/index.html", 0},
        {"最大輸入","XXXXXXXXXXXXXXXXXXXXXXXXXX", -1},
        {NULL, NULL, 0}
    }, *p = ps;

    QTest::addColumn<QString>("path");
    QTest::addColumn<int>("path_len");
    QTest::addColumn<int>("except");

    for (; p->desc != NULL; p++) {
        int len = p->path == nullptr ? (int)0:(int)strlen(p->path);
   	QTest::newRow(p->desc) << p->path << len << p->except;
   	//QTest::newRow(p->desc)    << p->path   << p->path == nullptr ? (int)1:(int)strlen(p->path) << p->except;
    }
   	//QTest::newRow(p->desc)    << p->path   << 1 << p->except;
    
}
void FormalVerification::HW3_stress_test()
{
    QFETCH(QString, path);
    QFETCH(int, path_len);
    QFETCH(int, except);

    StressTesting http_get;

    printf("\n現在測式: (%-20s) 輸入字串 :(\"%s\") 輸入長度: (%d) , 預期回傳值: (%d)\n", 
       QTest::currentDataTag(), path.toLocal8Bit().data(), path_len, except);

    QCOMPARE(except, http_get.testStressTesting((char *) path.toLocal8Bit().data(), path_len));
}
#endif

void FormalVerification::HW3_test_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    struct patten{
        const char *desc;
        const char *path;
        int except;
    } ps [] = {
        {"空指標", nullptr, -9},
        {"長度為0", "", -8},
        {"最小輸入", "/", 0},
        {"not_found","/indexx.html", -1},
        {"最大輸入","XXXXXXXXXXXXXXXXXXXXXXXXXX", -7},
        {nullptr, nullptr, 0}
    }, *p = ps;

    StressTesting http_get;

    for (; p->desc != nullptr; p++) {
        int len = p->path == nullptr ? 0:static_cast<int>(strlen(p->path));
        QString descriptions = QString("(%1)(input str: %2)(input length: %3)(exception %4)")
                .arg(QString(p->desc)).arg(p->path==nullptr?"null":p->path).arg(len).arg(p->except);

        QTest::newRow(descriptions.toStdString().c_str()) <<http_get.testStressTesting(p->path,len) << p->except;
    }

}

void FormalVerification::HW3_test()
{
    QFETCH(int, result);
    QFETCH(int, except);

    QCOMPARE(except,result);
}

QTEST_APPLESS_MAIN(FormalVerification)

#include "tst_formalverification.moc"
