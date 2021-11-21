#include "logicalexpression.h"


int LogicalExpression::testLogicalExpression(int* Amounts, int amountSize, bool isBlackFriday,
                                             bool isChristmas)
{
        // config
        int amount_to_get_discount = 1000;
        float special_discount = 1.0;
        
        // calculate total_amount
        int total_amount = 0;
        for(int i=0; i < amountSize; ++i)
        {
                total_amount += Amounts[i];
        }

        // calculate discount
        if ( total_amount >= amount_to_get_discount && ( isBlackFriday || isChristmas ) )
        {
                special_discount = 0.65;
        }else{
                special_discount = 0.9;
        }

        total_amount = (int)(total_amount * special_discount);
        
        return total_amount;
}
