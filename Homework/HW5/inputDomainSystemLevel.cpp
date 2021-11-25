#include "inputdomain.h"

uint32_t InputDomain::finalGrade(int32_t subject, QList<uint8_t> &points)
{
    uint32_t result = SubjectOutOfRange;

    if(subject >= SUBJECT_MAX)
        return  result;

    uint32_t numbersOfPoints = static_cast<uint32_t>(points.size());

    /// === abnormal ===
    if(numbersOfPoints != 3){
        if(numbersOfPoints > 3){
            if(subject == SUBJECT_MATH)
                result = MATH_OVER_THREE;
            else
                result = LANG_OVER_THREE;
        } else { // numbersOfPoints < 3
            result = LANG_MISSED_ALL - numbersOfPoints;
            if(subject == SUBJECT_MATH)
                result += (MATH_MISSED_ALL-LANG_MISSED_ALL);
        }
        return result;
    }

    /// === normally ===
    double aver = 0;
    for(auto point:points)
    {
        if(point >100)
        {
            if(subject == SUBJECT_MATH)
                return MATH_PointOutOfRange;
            else
                return LANG_PointOutOfRange;

        }
        aver += point;
    }
    aver /= numbersOfPoints;

    /// === judgement ===
    if(aver >=70)
    {
        result = LANG_Pass;
    }
    else{
        result = LANG_Failed;
    }

    if(subject == SUBJECT_MATH)
        result += (MATH_PointOutOfRange-LANG_PointOutOfRange);

    return  result;
}
