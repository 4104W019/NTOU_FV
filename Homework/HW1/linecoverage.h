#ifndef LINECOVERAGE_H
#define LINECOVERAGE_H


class LineCoverage
{
public:
    LineCoverage();

    /**
     * @brief theScoreGrade
     *  Used to be an unit test API.
     * @param i [IN]: the score
     * @return 'X': <0 or >100; 'A'>=90; 'B'>=80'; otherwise 'C': 0~79
     */
    char theScoreGrade(int i);
};

#endif // LINECOVERAGE_H
