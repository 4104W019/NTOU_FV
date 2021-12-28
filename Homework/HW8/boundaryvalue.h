#ifndef BOUNDARYVALUE_H
#define BOUNDARYVALUE_H
/**
 * Logical Expressions coverage  (the number of clauses > 1)
案例的條件至少包含兩個子句(子條件)

(Testing-Introduction.ppt p.62:
4-1)	Predicate Coverage(整個條件的 True False)
4-2)	Clause Coverage(每個子條件的 True False)
4-3)	Combinatorial Coverage(各種可能的排列組合)
 *
*/


/**
 * @brief The BoundaryValue class
 */
class BoundaryValue
{
public:
    BoundaryValue(){}
    int testBoundaryValue(int current_temperature);
};

#endif // BOUNDARYVALUE_H
