#include <QtTest>

// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"
#include "HW3/stresstesting.h"
#include "HW4/logicalexpression.h"
#include "HW6/mutations.h"

class Testing : public QObject
{
    Q_OBJECT

public:
    Testing();
    ~Testing();
private:
    void HW3_test_data();
    void HW3_test();
//private:
    /**
     * @brief test_case1_data
     * fill the test pattern for test_case1.
     */
    void HW1_test_data();

    /**
     * @brief test_case1
     * The test data has two elements, bool except and result
     * To fetch these values in the actual test
     */
    void HW1_test();
//private:
    void HW2_test_data();
    void HW2_test();
    void HW22_test_data();
    void HW22_test();
    void HW4_test_data();
    void HW4_test();
private slots:
    void HW6_test_data();
    void HW6_test();
};

Testing::Testing()
{

}

Testing::~Testing()
{

}

void Testing::HW1_test_data()
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

void Testing::HW1_test()
{
    QFETCH(int, result);
    QFETCH(int, except);

    QCOMPARE(result, except);
}

void Testing::HW2_test_data()
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

void Testing::HW2_test()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

void Testing::HW22_test_data()
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

void Testing::HW22_test()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

void Testing::HW3_test_data()
{
    struct patten{
        const char *desc;
        const char *path;
        int except;
    } ps [] = {
        {"空指標", NULL, -1},
        {"長度為0", "", -1},
        {"最小輸入", "/", 0},
        {"最大輸入","XXXXXXXXXXXXXXXXXXXXXXXXXX", -1},
        {"有效值","/index.html", 0},
        {"無效值","/unkown.html", -1},
        {NULL, NULL, 0}
    }, *p = ps;


    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    StressTesting http_get;

    for (; p->desc != nullptr; p++) {
        int len = p->path == nullptr ? 0:static_cast<int>(strlen(p->path));
        int ret;

        ret = http_get.testStressTesting((char *)p->path,len);

        QString descriptions = QString("現在測式:(%1), 輸入字串:(%2), 輸入長度(%3), 期望輸出(%4) 實際輸出(%5)")
            .arg(QString(p->desc), +5, QLatin1Char(' '))
            .arg(p->path==nullptr?"null":p->path)
            .arg(len)
            .arg(p->except)
            .arg(ret);
        QTest::newRow(descriptions.toStdString().c_str()) << ret << p->except;
    }
}
void Testing::HW3_test()
{
    QFETCH(int, result);
    QFETCH(int, except);

    QCOMPARE(except,result);
}
void Testing::HW4_test_data()
{
    QTest::addColumn<float>("result");
    QTest::addColumn<int>("except");
    LogicalExpression logicalExpression;
//    float test[4] = {3,-1,11,1.5};
//    int excepts[4] ={6,-1,-1,-1};

//    for(int i=0; i<4; ++i){
//        QTest::newRow(QString::number(test[i]).toStdString().c_str())
//                << logicalExpression.testLogicalExpression(test[i])
//                << excepts[i];
//    }
}
void Testing::HW4_test()
{
    QFETCH(float, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

void Testing::HW6_test_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");
    Mutations mutation;
    int test[5] = {-1,0,1,4,11};
    int excepts[5] ={-1,-1,1,10,-1};
//    for(int i=0; i<5; ++i){
//        QTest::newRow(QString::number(test[i]).toStdString().c_str())
//                << mutation.orgProgram(test[i])
//                << excepts[i];
//    }
        QTest::newRow(QString("mutProgram_1").toStdString().c_str()) << mutation.mutProgram_1(test[2]) << excepts[2];
        QTest::newRow(QString("mutProgram_2").toStdString().c_str()) << mutation.mutProgram_2(test[1]) << excepts[1];
        QTest::newRow(QString("mutProgram_3").toStdString().c_str()) << mutation.mutProgram_3(test[3]) << excepts[3];
        QTest::newRow(QString("mutProgram_4").toStdString().c_str()) << mutation.mutProgram_4(test[3]) << excepts[3];
        QTest::newRow(QString("mutProgram_5").toStdString().c_str()) << mutation.mutProgram_5(test[3]) << excepts[3];
        QTest::newRow(QString("mutProgram_6").toStdString().c_str()) << mutation.mutProgram_6(test[3]) << excepts[3];
        QTest::newRow(QString("mutProgram_7").toStdString().c_str()) << mutation.mutProgram_7(test[3]) << excepts[3];
        QTest::newRow(QString("mutProgram_8").toStdString().c_str()) << mutation.mutProgram_8(test[1]) << excepts[1];
}
void Testing::HW6_test()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}


QTEST_APPLESS_MAIN(Testing)

#include "tst_formalverification.moc"
