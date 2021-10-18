#include <QtTest>
// add necessary includes here

class LineCoverageTest : public QObject
{
    Q_OBJECT

    /**
     * @brief isGreatThanZero
     *  Used to be an unit test API.
     * @param i [IN]
     * @return true if i>=0, otherwise false
     */
    bool isGreatThanZero(int i);

public:
    LineCoverageTest();
    ~LineCoverageTest();

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

};


bool LineCoverageTest::isGreatThanZero(int i)
{
    if(i>=0)
        return true;
    else
        return false;
}


LineCoverageTest::LineCoverageTest()
{
}


LineCoverageTest::~LineCoverageTest()
{
}


void LineCoverageTest::test_case1_data()
{
    QTest::addColumn<bool>("except");
    QTest::addColumn<bool>("result");

    bool result = true;
    for(int i=-1; i<2; ++i){
        if(i<0)
            result = false;
        else result = true;
        QTest::newRow(QString::number(i).toStdString().c_str()) << isGreatThanZero(i) << result;
    }
}


void LineCoverageTest::test_case1()
{
    /**
     * @brief QFETCH
     * This macro can only be used in a test function that is invoked by the test framework.
     * The test function must have a _data function.
     */
    QFETCH(bool, except);
    QFETCH(bool, result);

    QCOMPARE(except, result);
}

QTEST_APPLESS_MAIN(LineCoverageTest)

#include "tst_linecoveragetest.moc"
