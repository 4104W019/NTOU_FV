#include "inputdomain.h"

int32_t InputDomain::domainOfExams(int32_t subject, int32_t point)
{
    if(subject >= SUBJECT_MAX)
        return  SubjectOutOfRange;//QString("SubjectOutOfRange");

    int grades;

    if(point<0 || point >100)
        grades = LANG_PointOutOfRange;
    else{
        if(point<70)
            grades = LANG_Failed;//QString("_Failed");
        else
            grades = LANG_Pass;//QString("_Pass");
    }
    if(subject==SUBJECT_MATH){
        grades += 3;
    }
    return grades;
}
