#include <QtTest>

// add necessary includes here
#include "HW1/linecoverage.h"
#include "HW2/edgecoverage.h"
#include "HW3/stresstesting.h"
#include "HW4/logicalexpression.h"
#include "HW5/inputdomain.h"
#include "HW6/mutations.h"
#include "HW7/inputbox_phone_number.h"
#include "HW8/boundaryvalue.h"


#include<QDebug>
class Testing : public QObject
{
    Q_OBJECT

public:
    Testing();
    ~Testing();

private slots:

    void HW8_test_data();
    void HW8_test();
    void HW7_validate_test_data();
    void HW7_validate_test();
    void HW6_test_data();
    void HW6_test();
    void HW5_system_data();
    void HW5_system();
    void HW4_test_data();
    void HW4_test();
    void HW3_test_data();
    void HW3_test();
    void HW2_test_data();
    void HW2_test();
    void HW22_test_data();
    void HW22_test();
    void HW1_test_data();
    void HW1_test();
private:
    void HW5_test_data();
    void HW5_test();

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
        QString description = QString("HW1(lineCoverage) Input = %1, Excepted = %2").arg(test[i]).arg(excepts[i]);
        QTest::newRow(description.toStdString().c_str())
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
        QString description = QString("HW2(edgeCoverage) Input = %1, Excepted = %2").arg(test[i]).arg(excepts[i]);
        QTest::newRow(description.toStdString().c_str())
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
        QString description = QString("HW22(testEdgePairCoverage) Input = %1, Excepted = %2").arg(test[i]).arg(excepts[i]);

        QTest::newRow(description.toStdString().c_str())
                << edgeCoverage.testEdgePairCoverage(test[i])
                << excepts[i];
    }
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

        QString descriptions = QString("HW3(StressTesting) 現在測式:(%1), 輸入字串:(%2), 輸入長度(%3), 期望輸出(%4) 實際輸出(%5)")
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
void Testing::HW22_test()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

void Testing::HW4_test_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    LogicalExpression LogicalExpression;

    // HW 4-1 test_case_01
    QString descriptions_test_case_01 = QString("HW4-1(LogicalExpression) test_case_01 -> total condition: true");
    int data_test_case_01[3] = { 100, 500, 600 };
    int *amounts = data_test_case_01;
    int amount_size = 3;
    bool is_black_friday = true;
    bool is_christmas = false;
    int discounted_amount = 780;

    QTest::newRow(descriptions_test_case_01.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;


    // HW 4-1 test_case_02
    QString descriptions_test_case_02 = QString("HW4-1(LogicalExpression) test_case_02 -> total condition: false");
    int data_test_case_02[3] = { 100, 500, 600 };
    amounts = data_test_case_02;
    is_black_friday = false;
    is_christmas = false;
    discounted_amount = 1080;

    QTest::newRow(descriptions_test_case_02.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;


    // HW 4-2 test_case_01
    QString descriptions_hw42_test_case_01 = QString("HW4-2(LogicalExpression) test_case_01 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true");
    int data_hw42_test_case_01[3] = { 100, 500, 600 };
    amounts = data_hw42_test_case_01;
    is_black_friday = true;
    is_christmas = true;
    discounted_amount = 780;

    QTest::newRow(descriptions_hw42_test_case_01.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;

    // HW 4-2 test_case_02
    QString descriptions_hw42_test_case_02 = QString("HW4-2(LogicalExpression) test_case_02 -> >= amount_to_get_discount: false, isBlackFriday: false, isChristmas: false");
    int data_hw42_test_case_02[3] = { 100, 200, 300 };
    amounts = data_hw42_test_case_02;
    is_black_friday = false;
    is_christmas = false;
    discounted_amount = 540;

    QTest::newRow(descriptions_hw42_test_case_02.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;


    // HW 4-3 test_case_01
    int data_hw43_true[3] = { 100, 500, 600 };
    int *amounts_true = data_hw43_true;
    int data_hw43_false[3] = { 100, 200, 300 };
    int *amounts_false = data_hw43_false;

    QString descriptions_hw43_test_case_01 = QString("HW4-3(LogicalExpression) test_case_01 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true");
    is_black_friday = true;
    is_christmas = true;
    discounted_amount = 780;
    QTest::newRow(descriptions_hw43_test_case_01.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;
    QString descriptions_hw43_test_case_02 = QString("HW4-3(LogicalExpression) test_case_02 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: true");
    discounted_amount = 540;
    QTest::newRow(descriptions_hw43_test_case_02.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;

    QString descriptions_hw43_test_case_03 = QString("HW4-3(LogicalExpression) test_case_03 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: false");
    is_black_friday = true;
    is_christmas = false;
    discounted_amount = 780;
    QTest::newRow(descriptions_hw43_test_case_03.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;
    QString descriptions_hw43_test_case_04 = QString("HW4-3(LogicalExpression) test_case_04 -> >= amount_to_get_discount: true, isBlackFriday: true, isChristmas: false");
    discounted_amount = 540;
    QTest::newRow(descriptions_hw43_test_case_04.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;

    QString descriptions_hw43_test_case_05 = QString("HW4-3(LogicalExpression) test_case_05 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: true");
    is_black_friday = false;
    is_christmas = true;
    discounted_amount = 780;
    QTest::newRow(descriptions_hw43_test_case_05.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;
    QString descriptions_hw43_test_case_06 = QString("HW4-3(LogicalExpression) test_case_06 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: true");
    discounted_amount = 540;
    QTest::newRow(descriptions_hw43_test_case_06.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;

    QString descriptions_hw43_test_case_07 = QString("HW4-3(LogicalExpression) test_case_07 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: false");
    is_black_friday = false;
    is_christmas = false;
    discounted_amount = 1080;
    QTest::newRow(descriptions_hw43_test_case_07.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_true, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;
    QString descriptions_hw43_test_case_08 = QString("HW4-3(LogicalExpression) test_case_08 -> >= amount_to_get_discount: true, isBlackFriday: false, isChristmas: false");
    discounted_amount = 540;
    QTest::newRow(descriptions_hw43_test_case_08.toStdString().c_str())
        << LogicalExpression.testLogicalExpression(amounts_false, amount_size,
                                                   is_black_friday, is_christmas)
        << discounted_amount;


}

void Testing::HW4_test()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

void Testing::HW5_system_data()
{
    QTest::addColumn<uint32_t>("result");
    QTest::addColumn<uint32_t>("except");

    InputDomain inputDomain;

    uint32_t categorization_excepts[7]={
        InputDomain::LANG_MISSED_ALL,
        InputDomain::MATH_MISSED_TWO,
        InputDomain::SubjectOutOfRange,
        InputDomain::LANG_Failed,
        InputDomain::MATH_Pass,
        InputDomain::SubjectOutOfRange,
        InputDomain::LANG_OVER_THREE
    };

    //int32_t subject[3] ={InputDomain::SUBJECT_LANG,InputDomain::SUBJECT_MATH,InputDomain::SUBJECT_MAX};

    QList<uint8_t> points[7];
    points[0].clear();  // lang
    points[1]={10};  //math
    points[2]={10,20}; // max
    points[3]={10,20,30}; //lang
    points[4]={80,90,100}; // math
    points[5]={90,100,110}; // max
    points[6]={1,2,3,4,5}; // lang

#if 1
    ///5-1)	categorization (每個類別)
    for(int32_t i=0; i<7;i++){
        uint32_t ret = inputDomain.finalGrade(i%3,points[i]);

        QString description = QString("HW5-1(categorization) %1 Categorization, subject(%2), output(%3) expect(%4)")
                                  .arg(i+1)
                                  .arg(i%3)
                                  .arg(categorization_excepts[i])
                                  .arg(ret);

        QTest::newRow(description.toStdString().c_str())
            << ret
            << categorization_excepts[i];
    }
#endif
    ///5-2)	Combinatorial (各種類別的排列組合)
#if 1
    uint32_t combinatorial_excepts[3][7]={
        {
            InputDomain::LANG_MISSED_ALL,
            InputDomain::LANG_MISSED_TWO,
            InputDomain::LANG_MISSED_ONE,
            InputDomain::LANG_Failed,
            InputDomain::LANG_Pass,
            InputDomain::LANG_PointOutOfRange,
            InputDomain::LANG_OVER_THREE
        },
        {
            InputDomain::MATH_MISSED_ALL,
            InputDomain::MATH_MISSED_TWO,
            InputDomain::MATH_MISSED_ONE,
            InputDomain::MATH_Failed,
            InputDomain::MATH_Pass,
            InputDomain::MATH_PointOutOfRange,
            InputDomain::MATH_OVER_THREE
        },
        {
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange,
            InputDomain::SubjectOutOfRange
        }
    };

    for(int32_t i=0; i<3;i++){
        for(int32_t j=0; j<7;j++){
            uint32_t ret = inputDomain.finalGrade(i,points[j]);

            QString description = QString("HW5-2(Combinatorial) %1 Combinatorial, subject(%2), output(%3)  expect(%4)")
                                      .arg(i*7+j+1)
                                      .arg(i)
                                      .arg(ret)
                                      .arg(combinatorial_excepts[i][j]);

            QTest::newRow(description.toStdString().c_str())
                << ret
                << combinatorial_excepts[i][j];
        }
    }
#endif
}

void Testing::HW5_system()
{
    QFETCH(uint32_t, except);
    QFETCH(uint32_t, result);

    QCOMPARE(except, result);
}



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

void Testing::HW7_validate_test_data()
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

        QString descriptions = QString("HW7(validate_test) 現在測式:(%1), 輸入電話:(%2), 輸入長度(%3), 期望輸出(%4) 實際輸出(%5)")
                                   .arg(QString(p->desc), +5, QLatin1Char(' '))
                                   .arg(p->phone_no)
                                   .arg(p->phone_no.length())
                                   .arg(p->except)
                                   .arg(ret);

        QTest::newRow(descriptions.toStdString().c_str()) << ret << p->except;
    }


}

void Testing::HW7_validate_test()
{
    QFETCH(int, result);
    QFETCH(int, except);

    QCOMPARE(except,result);
}

void Testing::HW8_test_data()
{
    QTest::addColumn<int>("result");
    QTest::addColumn<int>("except");

    BoundaryValue BoundaryValue;
    
    // HW 8 test_case_01
    QString descriptions_test_case_01 = QString("HW8(Boundary) test_case_01 -> current_temperature: 15");
    int current_temperature = 15;
    int excepted_status = 1;

    QTest::newRow(descriptions_test_case_01.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_02
    QString descriptions_test_case_02 = QString("HW8(Boundary) test_case_02 -> current_temperature: 16");
    current_temperature = 16;
    excepted_status = 1;

    QTest::newRow(descriptions_test_case_02.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_03
    QString descriptions_test_case_03 = QString("HW8(Boundary) test_case_03 -> current_temperature: 17");
    current_temperature = 17;
    excepted_status = 0;

    QTest::newRow(descriptions_test_case_03.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_04
    QString descriptions_test_case_04 = QString("HW8(Boundary) test_case_04 -> current_temperature: 27");
    current_temperature = 27;
    excepted_status = 0;

    QTest::newRow(descriptions_test_case_04.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_05
    QString descriptions_test_case_05 = QString("HW8(Boundary) test_case_05 -> current_temperature: 28");
    current_temperature = 28;
    excepted_status = 2;

    QTest::newRow(descriptions_test_case_05.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

    // HW 8 test_case_06
    QString descriptions_test_case_06 = QString("HW8(Boundary) test_case_06 -> current_temperature: 29");
    current_temperature = 29;
    excepted_status = 2;

    QTest::newRow(descriptions_test_case_06.toStdString().c_str())
                  << BoundaryValue.testBoundaryValue(current_temperature)
                  << excepted_status;

}

void Testing::HW8_test()
{
    QFETCH(int, except);
    QFETCH(int, result);

    QCOMPARE(except, result);
}

QTEST_APPLESS_MAIN(Testing)

#include "tst_formalverification.moc"
