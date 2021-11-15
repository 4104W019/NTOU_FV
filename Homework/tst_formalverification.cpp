#include <QtTest>

// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"
#include "HW3/stresstesting.h"

class Testing : public QObject
{
    Q_OBJECT

public:
    Testing();
    ~Testing();
private slots:
    void HW5_test_data();
    void HW5_test();
private:
    void HW3_test_data();
    void HW3_test();
        void HW2_test_data();
        void HW2_test();
        void HW22_test_data();
        void HW22_test();
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


};

Testing::Testing()
{

}

Testing::~Testing()
{

}
#include "HW5/inputdomain.h"
void Testing::HW5_test_data()
{
    QTest::addColumn<int32_t>("result");
    QTest::addColumn<int32_t>("except");

    InputDomain inputDomain;

    int32_t categorization_excepts[6]={
        InputDomain::LANG_PointOutOfRange,
        InputDomain::MATH_Failed,
        InputDomain::SubjectOutOfRange,
        InputDomain::LANG_Pass,
        InputDomain::MATH_Pass,
        InputDomain::SubjectOutOfRange};

    int32_t subject[3] ={InputDomain::SUBJECT_LANG,InputDomain::SUBJECT_MATH,InputDomain::SUBJECT_MAX};
    int32_t points[6] ={-1,0,69,70,100,101};


    ///5-1)	categorization (每個類別)
    for(int32_t i=0; i<6;i++){
        int32_t ret = inputDomain.domainOfExams(subject[i%3],points[i]);

        QString description = QString("5-1)Categorization, input(%1,%2), expect(%3) actual output(%4)")
               .arg(subject[i%3])
               .arg(points[i])
               .arg(categorization_excepts[i])
               .arg(ret);

        QTest::newRow(description.toStdString().c_str())
                << ret
                << categorization_excepts[i];
    }

    ///5-2)	Combinatorial (各種類別的排列組合)

    int32_t combinatorial_excepts[3][6]={
        {
            InputDomain::LANG_PointOutOfRange,
            InputDomain::LANG_Failed,
            InputDomain::LANG_Failed,
            InputDomain::LANG_Pass,
            InputDomain::LANG_Pass,
            InputDomain::LANG_PointOutOfRange
        },
        {
            InputDomain::MATH_PointOutOfRange,
            InputDomain::MATH_Failed,
            InputDomain::MATH_Failed,
            InputDomain::MATH_Pass,
            InputDomain::MATH_Pass,
            InputDomain::MATH_PointOutOfRange
        },
        {
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange
        }
       };

    for(int32_t i=0; i<3;i++){
        for(int32_t j=0; j<6;j++){
            int32_t ret = inputDomain.domainOfExams(subject[i],points[j]);

            QString description = QString("5-2)Combinatorial, input(%1,%2), expect(%3) actual output(%4)")
                    .arg(subject[i])
                    .arg(points[j])
                    .arg(combinatorial_excepts[i][j])
                    .arg(ret);

                QTest::newRow(description.toStdString().c_str())
                        << ret
                        << combinatorial_excepts[i][j];
        }
    }
}

void Testing::HW5_test()
{
    QFETCH(int32_t, except);
    QFETCH(int32_t, result);

    QCOMPARE(except, result);
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

QTEST_APPLESS_MAIN(Testing)

#include "tst_formalverification.moc"
