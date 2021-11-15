#ifndef INPUTDOMAIN_H
#define INPUTDOMAIN_H
#include <stdint.h>
#include <QString>
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
        SubjectOutOfRange
    };
    /**
     * @brief domainOfExams
     * @param subject: 0, 1;
     * @param point: [0~100];
     * @return
     */
    int32_t domainOfExams(int32_t subject, int32_t point);
};

#endif // INPUTDOMAIN_H
