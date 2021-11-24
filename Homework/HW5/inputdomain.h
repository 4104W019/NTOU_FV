#ifndef INPUTDOMAIN_H
#define INPUTDOMAIN_H
#include <stdint.h>
#include <QString>
#include <QList>
/**
 * Input Domain Characterization
(Testing-Introduction.ppt p.65:
5-1)	categorization (每個類別)
5-2)	Combinatorial (各種類別的排列組合)
 *
*/

/**
 * @brief The InputDomain class
 */
class InputDomain
{

public:
    InputDomain(){}
    enum SUBJECT{
        SUBJECT_LANG=0,
        SUBJECT_MATH,
        SUBJECT_MAX
    };
    enum EXCEPTS{
        LANG_PointOutOfRange=0,
        LANG_Failed,
        LANG_Pass,
        MATH_PointOutOfRange,
        MATH_Failed,
        MATH_Pass,
        LANG_MISSED_ONE,
        LANG_MISSED_TWO,
        LANG_MISSED_ALL,
        LANG_OVER_THREE,
        MATH_MISSED_ONE,
        MATH_MISSED_TWO,
        MATH_MISSED_ALL,
        MATH_OVER_THREE,
        SubjectOutOfRange
    };


    //( <=0, 1, >1 )

    /**
     * @brief domainOfExams
     * @param subject: 0, 1;
     * @param point: [0~100];
     * @return
     */
    int32_t domainOfExams(int32_t subject, int32_t point);

    /**
     * @brief Used to measure the grade.
     * @param subject: 0, 1:
     * @param points[IN]: a list of grade point
     * @return
     */
    uint32_t finalGrade(int32_t subject, QList<uint8_t> &points);
};

#endif // INPUTDOMAIN_H
